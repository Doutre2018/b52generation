#include "Cercle.h"



Cercle::Cercle(Point2d point, int radius)
	:mX{ point.x },
	mY{ point.y },
	mRadius{ radius }
{
}


Cercle::~Cercle()
{
}

int64_t Cercle::encodePropreties()
{
	
	int mask{ 0b1111'1111'1111'1111 };

	
}
