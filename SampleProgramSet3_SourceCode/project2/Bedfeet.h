// Bedfeet.h

#ifndef Bedfeet_H
#define Bedfeet_H

#include "ModelViewWithPhongLighting.h"

class Bedfeet : public ModelViewWithPhongLighting
{
public:
	Bedfeet(float width, float height, const cryph::AffPoint& bottom_midpoint);
	virtual ~Bedfeet();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimitsF) const;
	void render();
private:
	GLuint vao[1];
	GLuint vbo[2]; // 0: coordinates; 1: normal vectors

	float radius, xmin, xmax, ymin, ymax, zmin, zmax;

	void renderBedfeet();
};

#endif
