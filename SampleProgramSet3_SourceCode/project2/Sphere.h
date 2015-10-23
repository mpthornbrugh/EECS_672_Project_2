// Sphere.h

#ifndef Sphere_H
#define Sphere_H

#include "ModelViewWithPhongLighting.h"

class Sphere : public ModelViewWithPhongLighting
{
public:
	Sphere(const cryph::AffPoint& midpoint, float radius);
	virtual ~Sphere();

	// xyzLimits: {mcXmin, mcXmax, mcYmin, mcYmax, mcZmin, mcZmax}
	void getMCBoundingBox(double* xyzLimitsF) const;
	void render();
private:
	GLuint vao[1];
	GLuint vbo[2]; // 0: coordinates; 1: normal vectors

	float xmin, xmax, ymin, ymax, zmin, zmax;

	void renderSphere();
};

#endif
