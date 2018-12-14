<<<<<<< HEAD

#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <stdint.h>

#define _USE_MATH_DEFINES
#include <cmath>
=======
#ifndef SHAPE2D_H
#define SHAPE2D

#include "Point2d.h"
>>>>>>> 3757d03158beed1f9b9b487193dd780fd9f4cf63

class Shape2D
{
public:
	Shape2D(Point2d point, int height, int width);
	~Shape2D();

<<<<<<< HEAD

protected:
	virtual int64_t encodePropreties() = 0;

};

#endif //SHAPE2D_H
=======
protected:
	int mX;
	int mY;
	int mHeight;
	int mWidth;

};

#endif //SHAPE2D
>>>>>>> 3757d03158beed1f9b9b487193dd780fd9f4cf63
