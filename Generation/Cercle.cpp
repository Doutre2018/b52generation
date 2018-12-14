#include "Cercle.h"

Cercle::Cercle(Point2d point, int radius)
	:mPoint{point},
	mRadius{ radius }
{
	
}


Cercle::~Cercle()
{
}

int64_t Cercle::encodePropreties()
{
	
	int mask{ 0b1111'1111'1111'1111 };

	return (mX & mask) << 12 | (mY & mask) << 12 | (mRadius & mask);
}

int Cercle::calculateArea() {
	int d = calculateDiameter();
	return (M_PI*(d*d)) / 4;
}


int Cercle::calculateCirconference() {
	return 2 * M_PI * mRadius;
}

int Cercle::calculateDiameter() {
	return 2 * mRadius;
}