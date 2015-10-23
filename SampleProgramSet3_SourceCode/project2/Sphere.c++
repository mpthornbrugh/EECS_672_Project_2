// Sphere.c++

#include "Sphere.h"
#include "ShaderIF.h"

const int N_POINTS_AROUND_SLICE = 8; // number points around a cross-section

Sphere::Sphere(const cryph::AffPoint& midpoint, float radius)
{
	xmin = midpoint.x - radius;
	xmax = midpoint.x + radius;
	ymin = midpoint.y - radius;
	ymax = midpoint.y + radius;
	zmin = midpoint.z - radius;
	zmax = midpoint.z + radius;

	typedef float vec3[3];
	int nPoints = 2 * (N_POINTS_AROUND_SLICE + 1);
	vec3* coords = new vec3[nPoints];
	vec3* normals = new vec3[nPoints];
	double theta = 0.0;
	double dTheta = 2*M_PI/N_POINTS_AROUND_SLICE;
	double xb = midpoint.x;
	double zb = midpoint.z;
	double yb = midpoint.y;

	double r = radius;
}

Sphere::~Sphere()
{
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void Sphere::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = -1000.0; // xmin  Give real values!
	xyzLimits[1] = 1000.0;  // xmax         |
	xyzLimits[2] = -1234.5; // ymin         |
	xyzLimits[3] = -1011.2; // ymax         |
	xyzLimits[4] = -3000.0; // zmin         |
	xyzLimits[5] = -2000.0; // zmax        \_/
}

void Sphere::renderSphere()
{
}

void Sphere::render()
{
}
