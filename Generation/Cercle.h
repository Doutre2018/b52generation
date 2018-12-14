#pragma once
#include "Shape2D.h"
#include "Point2d.h"


class Cercle : protected Shape2D
{
public:
	Cercle(Point2d point, int radius);
	~Cercle();

private:
	int mX;
	int mY;
	int mRadius;


	virtual int64_t encodePropreties() override;
};
