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

int Cercle::borderProximity(size_t width, size_t height)
{
	int leftSide{ width - mX };

	if(mRadius < lef)

}


int Cercle::calculateArea() {
	int d = calculateDiameter();
	return (mPi*(d*d)) / 4;
}

int Cercle::calculateCirconference() {
	return 2 * mPi * mRadius;
}

int Cercle::calculateDiameter() {
	return 2 * mRadius;
}
 
void Cercle::randomize(size_t width, size_t height) {
	mX = Random::getInstance().uniformRandomize(0, width);
	mY = Random::getInstance().uniformRandomize(0, height);
	mPoint=Point2d(mX, mY);
//	size_t maxRadiusX;
//	size_t maxRadiusY;
//	if (width - mX > mX) {
//
//	}
//	else {
//
//	}
//	if (height - mY > mY) {
//
//	}
//	else {
//
//	}
	mRadius = Random::getInstance().uniformRandomize(0, height);
}
void Cercle::draw(ConsoleImage & image, ConsoleColor::Text color) {
	image.drawCircle(mX, mY, mRadius, 178, ConsoleColor::bb + color);
}
