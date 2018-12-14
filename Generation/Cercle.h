#ifndef CERCLE_H
#define CERCLE_H

#include "Shape2D.h"
#include "Point2d.h"


class Cercle : public Shape2D
{
public:
	Cercle(Point2d point, int radius);
	~Cercle();

	virtual int64_t encodePropreties() override;
	virtual void decodePropreties(int64_t data) override;
	int calculateArea();
	int calculateCirconference();
	int calculateDiameter();
	void draw(ConsoleImage & image);

private:
	int mX;
	int mY;
	Point2d mPoint;
	int mRadius;

};
#endif //CERCLE_H

