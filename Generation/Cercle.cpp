#include "Cercle.h"
#include "Area.h"
#define PI 3.14159265358979323846

Cercle::Cercle(Point2d point, int radius)
	:mPoint{point},
	mRadius{ radius }
{
	mX = mPoint.x();
	mY = mPoint.y();
}

Cercle::~Cercle()
{
}

int64_t Cercle::encodePropreties()
{
	int64_t mask{ 0b1111'1111 };

	return ((mX & mask) << 8 | (mY & mask) << 16 | (mRadius & mask));
}

void Cercle::decodePropreties(int64_t data)
{
	int64_t mask{ 0b1111'1111 };

	mRadius = mask & data;
	mY = (data >> 16) & mask;
	mX = (data >> 8) & mask;
}

bool Cercle::pointInShape()
{

	for (auto Point2d : Area::getInstance().points())
	{
		if (mPoly.contained(Point2d))
			return true;
	}

	return false;
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

void Cercle::draw(ConsoleImage & image, ConsoleColor::Text color) {
	image.drawCircle(mPoint.x(), mPoint.y(), mRadius, 178, ConsoleColor::bb + color);
}
