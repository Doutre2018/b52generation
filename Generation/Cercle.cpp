#include "Cercle.h"

Cercle::Cercle(Point2d point, int radius)
	:mPoint{point},
	mRadius{ radius },
	Shape2D(point, radius, radius)
{
	
}


Cercle::~Cercle()
{
}

int64_t Cercle::encodePropreties()
{
	int64_t mask{ 0b1111'1111'1111'1111 };

	return (mX & mask) << 24 | (mY & mask) << 12 | (mRadius & mask);
}

void Cercle::decodePropreties(int64_t data)
{
	int64_t mask{ 0b1111'1111'1111'1111 };

	mRadius = mask & data;
	mask << 12;

	mY = mask & data;
	mask << 24;

	mX = mask & data;
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