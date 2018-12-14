#ifndef SHAPE2D_H
#define SHAPE2D

#include "Point2d.h"

class Shape2D
{
public:
	Shape2D(Point2d point, int height, int width);
	~Shape2D();

protected:
	int mX;
	int mY;
	int mHeight;
	int mWidth;
	virtual int calculateArea()=0;

};

#endif //SHAPE2D