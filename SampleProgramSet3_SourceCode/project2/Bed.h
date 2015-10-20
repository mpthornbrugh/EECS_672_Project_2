// Bed.h

#ifndef Bed_H
#define Bed_H

#include "ModelViewWithPhongLighting.h"

class Bed : public ModelViewWithPhongLighting
{
public:
	Bed(const cryph::AffPoint& footLeft, const cryph::AffPoint& footRight, const cryph::AffPoint& headLeft, const cryph::AffPoint& headRight, float height);
	virtual ~Bed();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimitsF) const;
	void render();
private:
};

#endif
