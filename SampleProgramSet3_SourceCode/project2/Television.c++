// Television.c++

#include "Television.h"
#include "ShaderIF.h"

Television::Television(const cryph::AffPoint& frontMiddleBottomPoint, float width, float height, float depth)
{
	minx = frontMiddleBottomPoint - (width/2);
	maxx = frontMiddleBottomPoint + (width/2);
	miny = frontMiddleBottomPoint.y;
	maxy = frontMiddleBottomPoint.y + height;
	minz = frontMiddleBottomPoint.z;
	maxz = frontMiddleBottomPoint.z + depth;

	//Requires 16 vertices, with 14 normals
}

Television::~Television()
{
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void Television::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = minx;
	xyzLimits[1] = maxx;
	xyzLimits[2] = miny;
	xyzLimits[3] = maxy;
	xyzLimits[4] = minz;
	xyzLimits[5] = maxz;
}

void Television::renderTelevision()
{

}

void Television::render()
{
}
