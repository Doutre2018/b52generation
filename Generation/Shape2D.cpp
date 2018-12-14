#include "Shape2D.h"
#include "Point2d.h"


Shape2D::Shape2D(Point2d point, int height, int width)
	:mPoint{point},
	mHeight{ height },
	mWidth{ width }
{
}


Shape2D::~Shape2D()
{
}
