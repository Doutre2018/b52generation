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
	Shape2D(Point2d point, int height, int width);
	~Shape2D();
	virtual int64_t encodePropreties() = 0;
<<<<<<< HEAD
	virtual void decodePropreties(int64_t data) = 0;
=======
	virtual void draw(ConsoleImage & image) = 0;
protected:
	
>>>>>>> a062379626d091c97527fef71b64e7edd454c8aa

	int mX;
	int mY;
	int mHeight;
	int mWidth;
	Point2d	mPoint;

};

#endif //SHAPE2D_H