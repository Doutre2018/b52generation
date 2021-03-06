#ifndef SHAPE2D_H
#define SHAPE2D_H

#include <stdint.h>
#include "Point2d.h"
#include "Console\Console.h"


#define _USE_MATH_DEFINES
#include <cmath>

class Shape2D
{
public:
	Shape2D() : mX{ 0.0 }, mY{ 0.0 }, mHeight{ 0 }, mWidth{ 0 } {}
	~Shape2D(){}
	virtual int64_t encodePropreties() = 0;
	virtual void decodePropreties(int64_t data) = 0;

	virtual void draw(ConsoleImage & image, ConsoleColor::Text color) = 0;
	virtual int calculateArea() = 0;
	virtual double pointInShape(std::list<Point2d> points) = 0;
	virtual int borderProximity(size_t width, size_t height) = 0;
	virtual bool outOfBounds(size_t width, size_t height) = 0;
	virtual void randomize(size_t width, size_t height) = 0;
	//Point2d mPoint();

protected:
	double mX;
	double mY;
	int mHeight;
	int mWidth;
	Point2d	mPoint;
};

#endif //SHAPE2D_H