// Fanblade.h

#ifndef Fanblade_H
#define Fanblade_H

#include "ModelViewWithPhongLighting.h"

class Fanblade : public ModelViewWithPhongLighting
{
public:
	Fanblade(const cryph::AffPoint& connectionPoint, float length, float width, float depth);
	virtual ~Fanblade();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimitsF) const;
	void render();
private:
};

#endif
