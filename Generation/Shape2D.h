#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <stdint.h>
#include "Point2d.h"
#define _USE_MATH_DEFINES
#include <cmath>

class Shape2D
{
public:
	Shape2D(Point2d point, int height, int width);
	~Shape2D();

protected:
	virtual int64_t encodePropreties() = 0;
	virtual void decodePropreties(int64_t data) = 0;

	int mX;
	int mY;
	int mHeight;
	int mWidth;
	Point2d	mPoint;

};

#endif //SHAPE2D_H