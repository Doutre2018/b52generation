#ifndef CERCLE_H
#define CERCLE_H

#include "Shape2D.h"
#include "Point2d.h"
#include "Polygon2d.h"


class Cercle : public Shape2D
{
public:
	Cercle(Point2d point, int radius);
	~Cercle();

	int calculateArea();
	virtual int64_t encodePropreties() override;
	virtual void decodePropreties(int64_t data) override;
	virtual bool pointInShape() override;

	int calculateCirconference();
	int calculateDiameter();
	void draw(ConsoleImage & image, ConsoleColor::Text color);

private:
	int mX;
	int mY;
	Point2d mPoint;
	int mRadius;

	Polygon2d mPoly;

};
#endif //CERCLE_H

