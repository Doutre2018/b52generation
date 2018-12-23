#ifndef POlYGONAL_H
#define POLYGONAL_H
#include "Shape2D.h"
#include "Polygon2d.h"
class Polygonal :
	public Shape2D
{
public:
	Polygonal();
	~Polygonal();

	virtual int calculateArea() =0;
	virtual int64_t encodePropreties() = 0;
	virtual void decodePropreties(int64_t data) = 0;
	virtual double pointInShape(std::list<Point2d> points) = 0;
	virtual int borderProximity(size_t width, size_t height) = 0;
	virtual void randomize(size_t width, size_t height) = 0;
	virtual void draw(ConsoleImage & image, ConsoleColor::Text color) = 0;
};
#endif //POLYGON_H
