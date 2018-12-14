#include "Cercle.h"



Cercle::Cercle(Point2d point, int radius) :shape{ Shape2D(point,radius,radius) },
mRadius{ radius }
{
	
}


Cercle::~Cercle()
{
}

int Cercle::calculateArea() {
	int d = calculateDiameter();
	return (M_PI*(d*d)) / 4;
}

int Cercle::calculateDiameter() {
	return 2*radius;
}

int Cercle::calculateCirconference() {
	return 2 * M_PI * radius;
}

