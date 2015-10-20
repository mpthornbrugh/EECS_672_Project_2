// project2.c++: Starter for EECS 672 Project 2

#include "GLFWController.h"
#include "TEMPLATE_Subclass.h"

void set3DViewingInformation(double xyz[6])
{
	ModelView::setMCRegionOfInterest(xyz);

        double xmid = 0.5 * (xyz[0] + xyz[1]);
        double ymid = 0.5 * (xyz[2] + xyz[3]);
        double zmid = 0.5 * (xyz[4] + xyz[5]);
        cryph::AffPoint center(xmid, ymid, zmid);
        
        double maxDelta = xyz[1] - xyz[0];
        double delta = xyz[3] - xyz[2];
        if (delta > maxDelta)
            maxDelta = delta;
        delta = xyz[5] - xyz[4];
        if (delta > maxDelta)
            maxDelta = delta;
        double distEyeCenter = 2.0 * maxDelta;
        cryph::AffPoint eye(xmid, ymid, zmid + distEyeCenter);
        
	cryph::AffVector up = cryph::AffVector::yu;

	// Set values for eye-center-up to produce a reasonable off-axis
	// view of your scene, then:

	// Notify the ModelView of our MC->EC viewing requests:
	ModelView::setEyeCenterUp(eye, center, up);

	double ecZpp = -(distEyeCenter - 0.5*maxDelta);
        double ecZmin = ecZpp - maxDelta;
        double ecZmax = ecZpp + 0.5*maxDelta;

	// Set values for ecZpp, ecZmin, ecZmax that make sense in the context of
	// the EC system established above, then:

	ModelView::setProjection(PERSPECTIVE);
	ModelView::setProjectionPlaneZ(ecZpp);
	ModelView::setECZminZmax(ecZmin, ecZmax);
}

int main(int argc, char* argv[])
{
	GLFWController c("Bedroom", MVC_USE_DEPTH_BIT);
	c.reportVersions(std::cout);

	// create your scene, adding things to the Controller....

	glClearColor(1.0, 1.0, 1.0, 1.0);

	double xyz[6];
	c.getOverallMCBoundingBox(xyz);
	set3DViewingInformation(xyz);

	c.run();

	return 0;
}
