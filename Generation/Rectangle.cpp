#include "Rectangle.h"
#include "Random.h"


Rectangle::Rectangle():p()
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

double Rectangle::pointInShape(std::list<Point2d> points)
{
	return 0;
}

int Rectangle::borderProximity(size_t width, size_t height)
{
	return 0;
}

void Rectangle::randomize(size_t width, size_t height)
{
	mX = Random::getInstance().uniformRandomize(0, width);
	mY = Random::getInstance().uniformRandomize(0, height);
	mPoint = Point2d(mX, mY);

	p.buildRectangle(mWidth, mHeight, Point2d(mX, mY));
}

void Rectangle::draw(ConsoleImage & image, ConsoleColor::Text color)
{
	p.draw(image, color);
}
