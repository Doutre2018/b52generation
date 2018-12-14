#pragma once
#include <vector>
#include "Point.h"
#include "Point2d.h"
#include "Shape2d.h"

class Shape2D
{
public:
	Shape2D();
	~Shape2D();

	Point2d centerPoint(Shape2D polygon);

};

