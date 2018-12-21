#include "Rectangle.h"
#include "Random.h"


Rectangle::Rectangle()
{

}


Rectangle::~Rectangle()
{
}

int Rectangle::calculateArea()
{
	return 0;
}

int64_t Rectangle::encodePropreties()
{
	return int64_t();
}

void Rectangle::decodePropreties(int64_t data)
{
}

int Rectangle::pointInShape(std::list<Point2d> points)
{
	return 0;
}

int Rectangle::borderProximity(size_t width, size_t height)
{
	return 0;
}

void Rectangle::randomize(size_t width, size_t height)
{
	Polygon2d p;
	mX = Random::getInstance().uniformRandomize(0, width);
	mY = Random::getInstance().uniformRandomize(0, height);
	mPoint = Point2d(mX, mY);

	p.buildRectangle(mWidth, mHeight, Point2d(0.0, 0.0));
}

void Rectangle::draw(ConsoleImage & image, ConsoleColor::Text color)
{
}
