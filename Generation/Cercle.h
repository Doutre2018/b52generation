#ifndef CERCLE_H
#define CERCLE_H

#include "Shape2D.h"
<<<<<<< HEAD
#include "Point2d.h"


class Cercle : protected Shape2D
=======



class Cercle : public Shape2D
>>>>>>> 3757d03158beed1f9b9b487193dd780fd9f4cf63
{
public:
	Cercle(Point2d point, int radius);
	~Cercle();
<<<<<<< HEAD

private:
	int mX;
	int mY;
	Point2d mPoint;
	int mRadius;


	virtual int64_t encodePropreties() override;
	int calculateArea();
	int calculateCirconference();
	int calculateDiameter();
};
=======

private:

	int mX;
	int mY;
	int mRadius;
	Shape2D shape;


};

#endif //CERCLE_H
>>>>>>> 3757d03158beed1f9b9b487193dd780fd9f4cf63
