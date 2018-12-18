#ifndef CERCLE_H
#define CERCLE_H

#include "Shape2D.h"
#include "Point2d.h"
#include "Polygon2d.h"
#include "Random.h"

class Cercle : public Shape2D
{
public:
	Cercle();
	~Cercle();

	virtual int calculateArea() override;
	virtual int64_t encodePropreties() override;
	virtual void decodePropreties(int64_t data) override;
	virtual bool pointInShape(std::list<Point2d> points) override;
	virtual void randomize(size_t width, size_t height) override;
	virtual void draw(ConsoleImage & image, ConsoleColor::Text color) override;

	int calculateCirconference();
	int calculateDiameter();
	

private:
	const float mPi = 3.14159265358979323846;

	int mX;
	int mY;
	Point2d mPoint;
	int mRadius;
	Point2d mNearestPoint;

	Polygon2d mPoly;


};
#endif //CERCLE_H

