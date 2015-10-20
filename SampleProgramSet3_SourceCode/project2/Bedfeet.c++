// Bedfeet.c++

#include "Bedfeet.h"
#include "ShaderIF.h"

Bedfeet::Bedfeet(float width, float height, const cryph::AffPoint& bottom_midpoint)
{
}

Bedfeet::~Bedfeet()
{
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
