// Bedfeet.c++

#include "Bedfeet.h"
#include "ShaderIF.h"

const int N_POINTS_AROUND_SLICE = 18; // number points around a cross-section

Bedfeet::Bedfeet(float width, float height, const cryph::AffPoint& bottom_midpoint)
{
	radius = width/2;
	
	typedef float vec3[3];
	int nPoints = 2 * (N_POINTS_AROUND_SLICE + 1);
	vec3* coords = new vec3[nPoints];
	vec3* normals = new vec3[nPoints];
	double theta = 0.0;
	double dTheta = 2.0*M_PI/N_POINTS_AROUND_SLICE;
	double yb = -0.35, zb = 1.4;
	double x1 = 0.6, x2 = 1.1;
	double r = radius;
	// EXERCISE: Use cryph to generalize this to define a cylinder in
	//           an arbitrary position and orientation.
	for (int i=0 ; i<=N_POINTS_AROUND_SLICE ; i++)
	{
		int j = 2 * i;
		double dy = cos(theta);
		double dz = sin(theta);
		normals[j][0] = 0.0; normals[j][1] = dy; normals[j][2] = dz;
		coords[j][0] = x1; coords[j][1] = yb + r*dy; coords[j][2] = zb + r*dz;
		normals[j+1][0] = 0.0; normals[j+1][1] = dy; normals[j+1][2] = dz;
		coords[j+1][0] = x2; coords[j+1][1] = yb + r*dy; coords[j+1][2] = zb + r*dz;
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
	xyzLimits[0] = -1000.0; // xmin  Give real values!
	xyzLimits[1] = 1000.0;  // xmax         |
	xyzLimits[2] = -1234.5; // ymin         |
	xyzLimits[3] = -1011.2; // ymax         |
	xyzLimits[4] = -3000.0; // zmin         |
	xyzLimits[5] = -2000.0; // zmax        \_/
}

void Bedfeet::render()
{
}
