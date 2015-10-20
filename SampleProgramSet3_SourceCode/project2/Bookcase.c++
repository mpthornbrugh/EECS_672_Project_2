// Bookcase.c++

#include "Bookcase.h"
#include "ShaderIF.h"

Bookcase::Bookcase(const cryph::AffPoint& bottomRightPoint, float height, float width, float depth)
{
}

Bookcase::~Bookcase()
{
}

// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
void Bookcase::getMCBoundingBox(double* xyzLimits) const
{
	xyzLimits[0] = -1000.0; // xmin  Give real values!
	xyzLimits[1] = 1000.0;  // xmax         |
	xyzLimits[2] = -1234.5; // ymin         |
	xyzLimits[3] = -1011.2; // ymax         |
	xyzLimits[4] = -3000.0; // zmin         |
	xyzLimits[5] = -2000.0; // zmax        \_/
}

void Bookcase::render()
{
}
