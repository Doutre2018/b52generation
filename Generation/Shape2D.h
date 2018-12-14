#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <stdint.h>
#include "Point2d.h"
#include "Console\Console.h"

#define _USE_MATH_DEFINES
#include <cmath>

class Shape2D
{
public:
	Shape2D();
	~Shape2D();
	virtual int64_t encodePropreties() = 0;
	virtual void decodePropreties(int64_t data) = 0;
	virtual void draw(ConsoleImage & image, ConsoleColor::Text color) = 0;
	virtual int calculateArea() = 0;

protected:

	int mX;
	int mY;
	int mHeight;
	int mWidth;
	Point2d	mPoint;
};

#endif //SHAPE2D_H