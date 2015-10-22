// Bedfeet.c++

#include "Bedfeet.h"
#include "ShaderIF.h"

const int N_POINTS_AROUND_SLICE = 18; // number points around a cross-section

Bedfeet::Bedfeet(float width, float height, const cryph::AffPoint& bottom_midpoint)
{
	radius = width/2;

	xmin = bottom_midpoint.x - radius;
	xmax = bottom_midpoint.x + radius;
	ymin = bottom_midpoint.y;
	ymax = bottom_midpoint.y + height;
	zmin = bottom_midpoint.z - radius;
	zmax = bottom_midpoint.z + radius;
	
	typedef float vec3[3];
	int nPoints = 2 * (N_POINTS_AROUND_SLICE + 1);
	vec3* coords = new vec3[nPoints];
	vec3* normals = new vec3[nPoints];
	double theta = 0.0;
	double dTheta = 2.0*M_PI/N_POINTS_AROUND_SLICE;
	double xb = bottom_midpoint.x;
	double zb = bottom_midpoint.z;
	double y1 = bottom_midpoint.y;
	double y2 = bottom_midpoint.y + height;

	double r = radius;

	for (int i=0 ; i<=N_POINTS_AROUND_SLICE ; i++)
	{
		int j = 2 * i;
		double dx = cos(theta);
		double dz = sin(theta);
		normals[j][0] = dx; normals[j][1] = 0.0; normals[j][2] = dz;
		coords[j][0] = xb + r*dx; coords[j][1] = y1; coords[j][2] = zb + r*dz;
		normals[j+1][0] = dx; normals[j+1][1] = 0.0; normals[j+1][2] = dz;
		coords[j+1][0] = xb + r*dx; coords[j+1][1] = y2; coords[j+1][2] = zb + r*dz;
		theta += dTheta;
	}
}

Bedfeet::~Bedfeet()
{
	glDeleteBuffers(2, vbo);
	glDeleteVertexArrays(1, vao);
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void Bedfeet::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = xmin;
	xyzLimits[1] = xmax;
	xyzLimits[2] = ymin;
	xyzLimits[3] = ymax;
	xyzLimits[4] = zmin;
	xyzLimits[5] = zmax;
}

void Bedfeet::renderBedfeet()
{
	float color[] = { 0.0, 0.0, 0.0 };

	typedef float vec3[3];
	glUniform3fv(ppuLoc_kd, 1, color);
	glBindVertexArray(vao[0]);
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 2*(N_POINTS_AROUND_SLICE+1));
}

void Bedfeet::render()
{
	GLint pgm;
	glGetIntegerv(GL_CURRENT_PROGRAM, &pgm);
	glUseProgram(shaderProgram);

	cryph::Matrix4x4 mc_ec, ec_lds;
	getMatrices(mc_ec, ec_lds);
	float mat[16];
	glUniformMatrix4fv(ppuLoc_mc_ec, 1, false, mc_ec.extractColMajor(mat));
	glUniformMatrix4fv(ppuLoc_ec_lds, 1, false, ec_lds.extractColMajor(mat));\

	glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
	renderCylinder();

	glUseProgram(pgm);
}
