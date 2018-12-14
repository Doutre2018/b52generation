#ifndef CERCLE_H
#define CERCLE_H

#include "Shape2D.h"



class Cercle : public Shape2D
{
public:
	Cercle(Point2d point, int radius);
	~Cercle();

	int calculateArea();

private:

	int mX;
	int mY;
	int mRadius;


};

#endif //CERCLE_H