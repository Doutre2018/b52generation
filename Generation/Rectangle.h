#pragma once
#include "Polygonal.h"
class Rectangle :
	public Polygonal
{
public:
	Rectangle();
	~Rectangle();

	void create();

	virtual int calculateArea() override;
	virtual int64_t encodePropreties() override;
	virtual void decodePropreties(int64_t data) override;
	virtual double pointInShape(std::list<Point2d> points) override;
	virtual int borderProximity(size_t width, size_t height) override;
	virtual void randomize(size_t width, size_t height) override;
	virtual void draw(ConsoleImage & image, ConsoleColor::Text color) override;

private :
	Polygon2d p;

};

