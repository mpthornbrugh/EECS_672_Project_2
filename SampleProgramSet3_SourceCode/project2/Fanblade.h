// Fanblade.h

#ifndef Fanblade_H
#define Fanblade_H

#include "ModelViewWithPhongLighting.h"

class Fanblade : public ModelViewWithPhongLighting
{
public:
	Fanblade(const cryph::AffPoint& connectionPoint, int direction, float length, float width, float depth);
	virtual ~Fanblade();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimitsF) const;
	void render();
private:

	float xmin, xmax, ymin, ymax, zmin, zmax, radius;
};

#endif
