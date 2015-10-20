// Bed.c++

#include "Bed.h"
#include "ShaderIF.h"

Bed::Bed(const cryph::AffPoint& footLeft, const cryph::AffPoint& footRight, const cryph::AffPoint& headLeft, const cryph::AffPoint& headRight, float height)
{
}

Bed::~Bed()
{
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void Bed::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = -1000.0; // xmin  Give real values!
	xyzLimits[1] = 1000.0;  // xmax         |
	xyzLimits[2] = -1234.5; // ymin         |
	xyzLimits[3] = -1011.2; // ymax         |
	xyzLimits[4] = -3000.0; // zmin         |
	xyzLimits[5] = -2000.0; // zmax        \_/
}

void Bed::render()
{
}
