// Fanblade.c++

#include "Fanblade.h"
#include "ShaderIF.h"

//Connection point is on the bottom of the middle by where the blade meets the rest of the fan
Fanblade::Fanblade(const cryph::AffPoint& connectionPoint, int direction, float length, float width, float depth)
{
	radius = width/2;
	ymin = connectionPoint.y;
	ymax = connectionPoint.y + depth;
	cryph::AffPoint circularSectionMidPoint;
	if (direction == 1) { //Going along the positive x axis
		circularSectionMidPoint = (connectionPoint.x + (4*length/5), connectionPoint.y, connectionPoint.z);
		xmin = connectionPoint.x;
		xmax = connectionPoint.x + length;
		zmin = connectionPoint.z - radius;
		zmax = connectionPoint.z + radius;
	}
	else if (direction == 2) { //Going along the positive z axis
		circularSectionMidPoint = (connectionPoint.z, connectionPoint.y, connectionPoint.z + (4*length/5));
		xmin = connectionPoint.x - radius;
		xmax = connectionPoint.x + radius;
		zmin = connectionPoint.z;
		zmax = connectionPoint.z + length;
	}
	else if (direction == 3) { //Going along the negative x axis
		circularSectionMidPoint = (connectionPoint.x - (4*length/5), connectionPoint.y, connectionPoint.z);
		xmin = connectionPoint.x - length;
		xmax = connectionPoint.x;
		zmin = connectionPoint.z - radius;
		zmax = connectionPoint.z + radius;
	}
	else { //Going along the negative z axis
		circularSectionMidPoint = (connectionPoint.z, connectionPoint.y, connectionPoint.z - (4*length/5));
		xmin = connectionPoint.x - radius;
		xmax = connectionPoint.x + radius;
		zmin = connectionPoint.z - length;
		zmax = connectionPoint.z;
	}

	// The connection piece should be 1/5th the length 

	// The end piece should be 1/5 the length

	// The middle piece is the remaining 3/5 of the length
}

Fanblade::~Fanblade()
{

}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void Fanblade::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = -1000.0; // xmin  Give real values!
	xyzLimits[1] = 1000.0;  // xmax         |
	xyzLimits[2] = -1234.5; // ymin         |
	xyzLimits[3] = -1011.2; // ymax         |
	xyzLimits[4] = -3000.0; // zmin         |
	xyzLimits[5] = -2000.0; // zmax        \_/
}

void Fanblade::render()
{
}
