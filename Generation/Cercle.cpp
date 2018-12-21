#include "Cercle.h"

#include <list>

Cercle::Cercle(){}

Cercle::~Cercle(){}

int64_t Cercle::encodePropreties(){
	int64_t mask{ 0b1111'1111'11 };
	return (((mX & mask) << 10) | ((mY & mask) << 20) | (mRadius & mask));
}

void Cercle::decodePropreties(int64_t data){
	int64_t mask{ 0b1111'1111'11 };

	mRadius = mask & data;
	mY = (data >> 20) & mask;
	mX = (data >> 10) & mask;
}


bool Cercle::pointInShape(std::list<Point2d> points)
{
	for (auto point : points){
		if (point.distance(mPoint) < mRadius){
			if (point.distance(mPoint) < point.distance(mNearestPoint)){
				mNearestPoint = point;
			}
		}
	}

	if (mNearestPoint != NULL) {
		return true;
	} else {
		return false;
	}
}


int Cercle::calculateArea() {
	int d = 2 * mRadius;
	return (mPi*(d*d)) / 4;
}

void Cercle::randomize(size_t width, size_t height) {
	mX = Random::getInstance().uniformRandomize(0, width);
	mY = Random::getInstance().uniformRandomize(0, height);
	mPoint=Point2d(mX, mY);
	size_t maxRadiusX;
	size_t maxradiusy;
	size_t maxradius;
	if (width - mX > mX) {
		maxRadiusX = mX;
	}
	else {
		maxRadiusX = width- mX;
	}
	if (height - mY > mY) {
		maxradiusy  = mY;
	}
	else {
		maxradiusy = height- mY;
	}
	if (maxradiusy >= maxRadiusX) {
		maxradius = maxRadiusX;
	}
	else {
		maxradius = maxradiusy;
	}
	mRadius = Random::getInstance().uniformRandomize(0, maxradius);
}
void Cercle::draw(ConsoleImage & image, ConsoleColor::Text color) {
	image.drawCircle(mX, mY, mRadius, 178, ConsoleColor::bb + color);
}
