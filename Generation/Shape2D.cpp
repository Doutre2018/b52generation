#include "Shape2D.h"

#include "Polygon2d.h"


#include "Point2d.h"
#include "Cercle.h"



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
/*
double Shape2D::getArea() {
	return mArea;

}

*/
void Shape2D::createShapes(std::vector<Shape2D*> myShapes) {
	myShapes[0] = new Cercle();
	//myShapes[1] = new Cercle().Cercle::randomize();
	//mShape[2] = new Cercle().Cercle::randomize();



}
