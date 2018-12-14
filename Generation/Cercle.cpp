#include "Cercle.h"
#define PI 3.14159265358979323846
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
	
	int mask{ 0b1111'1111'1111'1111 };

	return (mX & mask) << 12 | (mY & mask) << 12 | (mRadius & mask);
}

int Cercle::calculateArea() {
	int d = calculateDiameter();
	return (PI*(d*d)) / 4;
}


int Cercle::calculateCirconference() {
	return 2 * PI * mRadius;
}

int Cercle::calculateDiameter() {
	return 2 * mRadius;
}

void Cercle::draw(ConsoleImage & image) {
	image.drawCircle(mPoint.x(), mPoint.y(), mRadius, 178, ConsoleColor::bb + ConsoleColor::tg);
}