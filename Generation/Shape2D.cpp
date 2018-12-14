#include "Shape2D.h"
#include "Polygon2d.h"



Shape2D::Shape2D()
{
}


Shape2D::~Shape2D()
{
}

/*   Temporary off, polygon shape construction pending 
Point2d Shape2D::centerPoint(Shape2D polygonOrigin) {

	Point2d topLeft;
	Point2d bottomRight;

	Polygon2d polygon;

	polygon.buildRegular(polygonOrigin.sides, polygonOrigin.radius, polygonOrigin.center, polygonOrigin.rotateDeg);


	topLeft = polygon.Polygon2d::boundingBoxTopLeft();
	bottomRight = polygon.Polygon2d::boundingBoxBottomRight();

	return bottomRight - topLeft / 2;


}
*/