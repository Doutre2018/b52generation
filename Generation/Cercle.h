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

	virtual int calculateArea() override;
	virtual int64_t encodePropreties() override;
	virtual void decodePropreties(int64_t data) override;
	virtual bool pointInShape() override;
	virtual void draw(ConsoleImage & image, ConsoleColor::Text color) override;
	void setSolution(double value);
	int calculateCirconference();
	int calculateDiameter();
	

private:
	int mX;
	int mY;
	Point2d mPoint;
	int mRadius;
	double solution;

	Polygon2d mPoly;

};
#endif //CERCLE_H

