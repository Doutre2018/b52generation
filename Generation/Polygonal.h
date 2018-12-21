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

	virtual int calculateArea() override;
	virtual int64_t encodePropreties() override;
	virtual void decodePropreties(int64_t data) override;
	virtual int pointInShape(std::list<Point2d> points) override;
	virtual int borderProximity(size_t width, size_t height) override;
	virtual void randomize(size_t width, size_t height) override;
	virtual void draw(ConsoleImage & image, ConsoleColor::Text color) override;
	virtual void 
};
#endif //POLYGON_H
