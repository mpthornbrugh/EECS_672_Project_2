// Television.h

#ifndef Television_H
#define Television_H

#include "ModelViewWithPhongLighting.h"

class Television : public ModelViewWithPhongLighting
{
public:
	Television(const cryph::AffPoint& frontMiddleBottomPoint, float width, float height, float depth);
	virtual ~Television();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimitsF) const;
	void render();
private:
};

#endif
