// project2.c++: Starter for EECS 672 Project 2

#include "GLFWController.h"
#include "Bedfeet.h"
#include "Bedfeet.c++"
#include "Block.h"
#include "Block.c++"
#include "HalfCylinder.h"
#include "HalfCylinder.c++"
#include "Sphere.h"
#include "Sphere.c++"

void addBed(Controller &c, const cryph::AffPoint& headLeftBottomPoint, float bedWidth, float bedLength, float bedHeight, float feetHeight, float feetWidth)
{
	//Bed Mattress
	c.addModel(new Block(headLeftBottomPoint.x, headLeftBottomPoint.y + feetHeight, headLeftBottomPoint.z, bedWidth, bedHeight, bedLength));

	//All feet are 3 inches in from the x and z ways

	//Head Left Foot
	cryph::AffPoint p0(headLeftBottomPoint.x + 30.0, headLeftBottomPoint.y, headLeftBottomPoint.z + 30.0);
	c.addModel(new Bedfeet(feetWidth, feetHeight, p0));

	//Head Right Foot
	p0.assign(headLeftBottomPoint.x + bedWidth - 30.0, headLeftBottomPoint.y, headLeftBottomPoint.z + 30.0);
	c.addModel(new Bedfeet(feetWidth, feetHeight, p0));

	//Foot Left Foot
	p0.assign(headLeftBottomPoint.x + 30.0, headLeftBottomPoint.y, headLeftBottomPoint.z + bedLength - 30.0);
	c.addModel(new Bedfeet(feetWidth, feetHeight, p0));

	//Foot Right Foot
	p0.assign(headLeftBottomPoint.x + bedWidth - 30.0, headLeftBottomPoint.y, headLeftBottomPoint.z + bedLength - 30.0);
	c.addModel(new Bedfeet(feetWidth, feetHeight, p0));
}

void addFan(Controller &c, const cryph::AffPoint& topMiddlePoint, float baseHeight, float baseWidth, float connectorHeight, float connectorWidth, float sphereRadius)
{

}

void addBookcase(Controller &c, const cryph::AffPoint& bottomFrontLeftPoint, float height, float width, float depth)
{
	//Making all shelf parts 1 inch thick

	//Each shelf is 12 inches from the last thing -1 because there won't be any on the top
	int numShelves = (height/120.0) - 1;

	//Bottom of bookcase
	c.addModel(new Block(bottomFrontLeftPoint.x + 10.0, bottomFrontLeftPoint.y, bottomFrontLeftPoint.z, width - 20.0, 10.0, depth - 10.0));

	//Top of bookcase
	c.addModel(new Block(bottomFrontLeftPoint.x + 10.0, bottomFrontLeftPoint.y + height - 10.0, bottomFrontLeftPoint.z, width - 20.0, 10.0, depth - 10.0));

	//Back of bookcase
	c.addModel(new Block(bottomFrontLeftPoint.x, bottomFrontLeftPoint.y, bottomFrontLeftPoint.z, width, height, 10.0));

	//Right of bookcase
	c.addModel(new Block(bottomFrontLeftPoint.x + width - 10.0, bottomFrontLeftPoint.y, bottomFrontLeftPoint.z, 10.0, height, depth - 10.0));

	//Left of bookcase
	c.addModel(new Block(bottomFrontLeftPoint.x, bottomFrontLeftPoint.y, bottomFrontLeftPoint.z, 10.0, height, depth - 10.0));

	float shelfHeight = bottomFrontLeftPoint.y + 120.0;

	//Add the shelves
	for (int i = 0; i < numShelves; i++) {
		c.addModel(new Block(bottomFrontLeftPoint.x + 10.0, shelfHeight, bottomFrontLeftPoint.z, width - 20.0, 10.0, depth - 10.0));
		shelfHeight += 120.0;
	}
}

// The position variable is either 1,2,3 or 4 for the direction that the fan blade is facing.
void addFanblade(Controller &c, const cryph::AffPoint& connectionPoint, float width, float length, float depth, int position)
{
	float lengthConnector = length/5.0;
	float middleSectionLength = 3.0*lengthConnector;
	float lengthCapPiece = lengthConnector;
	float widthConnector = width/3.0;
	if (position == 1) { //Go along x axis
		//Block (xlow, ylow, zlow, xLength, yLength, zLength)
		//HalfCyl (width, height, bottom_midpoint, startAngle)

		//Connector
		c.addModel(new Block(connectionPoint.x, connectionPoint.y, connectionPoint.z - widthConnector/2.0, lengthConnector, depth, widthConnector));

		//Middle Section
		c.addModel(new Block(connectionPoint.x + lengthConnector, connectionPoint.y, connectionPoint.z - width/2.0, middleSectionLength, depth, width));

		//Cap
		cryph::AffPoint cylPoint (connectionPoint.x + lengthConnector + middleSectionLength, connectionPoint.y, connectionPoint.z);
		c.addModel(new HalfCylinder(width, depth, cylPoint, -90.0));
	}
	else if (position == 2) { //Go along z axis
		//Connector
		c.addModel(new Block(connectionPoint.x - widthConnector/2.0, connectionPoint.y, connectionPoint.z, widthConnector, depth, lengthConnector));

		//Middle Section
		c.addModel(new Block(connectionPoint.x - width/2.0, connectionPoint.y, connectionPoint.z + lengthConnector, width, depth, middleSectionLength));

		//Cap
		cryph::AffPoint cylPoint (connectionPoint.x, connectionPoint.y, connectionPoint.z + lengthConnector + middleSectionLength);
		c.addModel(new HalfCylinder(width, depth, cylPoint, 180.0));
	}
	else if (position == 3) { //Go along -x axis
		//Connector
		c.addModel(new Block(connectionPoint.x - lengthConnector, connectionPoint.y, connectionPoint.z - widthConnector/2.0, lengthConnector, depth, widthConnector));

		//Middle Section
		c.addModel(new Block(connectionPoint.x - lengthConnector - middleSectionLength, connectionPoint.y, connectionPoint.z - width/2.0, middleSectionLength, depth, width));

		//Cap
		cryph::AffPoint cylPoint (connectionPoint.x - lengthConnector - middleSectionLength, connectionPoint.y, connectionPoint.z);
		c.addModel(new HalfCylinder(width, depth, cylPoint, 90.0));
	}
	else if (position == 4) { //Go along -z axis
		//Connector
		c.addModel(new Block(connectionPoint.x - widthConnector/2.0, connectionPoint.y, connectionPoint.z - lengthConnector, widthConnector, depth, lengthConnector));

		//Middle Section
		c.addModel(new Block(connectionPoint.x - width/2.0, connectionPoint.y, connectionPoint.z - middleSectionLength, width, depth, middleSectionLength));

		//Cap
		cryph::AffPoint cylPoint (connectionPoint.x, connectionPoint.y, connectionPoint.z - lengthConnector - middleSectionLength);
		c.addModel(new HalfCylinder(width, depth, cylPoint, 0.0));
	}
}

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
	cryph::AffPoint p0(1320.0,0.0,1320.0);
	addBookcase(c, p0, 480.0, 480.0, 120.0);

	p0.assign(720.0,0.0,1320.0);
	addBookcase(c, p0, 720.0, 480.0, 120.0);

	cryph::AffPoint p1(720.0, 0.0, 0.0);
	addBed(c, p1, 600.0, 840.0, 240.0, 120.0, 40.0);

	//addFan(Controller &c, const cryph::AffPoint& topMiddlePoint, float baseHeight, float baseWidth, float connectorHeight, float connectorWidth, float sphereRadius)
	cryph::AffPoint p2(660.0,960.0,660.0);
	addFan(c, p2, 120.0, 240.0, 120.0, 120.0, 180.0);

	glClearColor(1.0, 1.0, 1.0, 1.0);

	double xyz[6];
	c.getOverallMCBoundingBox(xyz);
	set3DViewingInformation(xyz);

	c.run();

	return 0;
}
