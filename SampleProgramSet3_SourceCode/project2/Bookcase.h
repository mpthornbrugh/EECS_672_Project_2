// Bookcase.h

#ifndef Bookcase_H
#define Bookcase_H

#include "ModelViewWithPhongLighting.h"

class Bookcase : public ModelViewWithPhongLighting
{
public:
	Bookcase(const cryph::AffPoint& bottomRightPoint, float height, float width, float depth);
	virtual ~Bookcase();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimitsF) const;
	void render();
private:
};

#endif
