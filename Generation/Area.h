#ifndef AREA_H
#define AREA_H

#include "Console\Console.h"
#include "Point2d.h"
#include "Random.h"
#include "Shape2D.h"
#include "Cercle.h"
#include "Solution.h"
#define SIZEW 350
#define SIZEH 200

#define NBPOPULATION 30

#define SHAPE "cercle"
#define NBOBSTACLES 100

class Area
{
private:
	Area();
	~Area();
public:
	std::string shape_g = "cercle";
	void setArea(size_t height, size_t width, std::string type, size_t nbPopulations, size_t nbObstacles);
	void generateArea();
	void generatePoint();
	void testArea();
	void showPoint();
	void showCivilisations();
	void drawShape(Shape2D ** liste, size_t size, ConsoleColor::Text color);
	static Area& getInstance()
	{
		static Area instance;
		return instance;
	}


	size_t sizeW() { return SIZEW; }
	size_t sizeH() { return SIZEH; }

	size_t nbObstacles() { return NBOBSTACLES; }
	std::string shape() { return shape_g; }


	std::list<Point2d> points();



private :
	ConsoleImage * area_m;
	ConsoleImage * mBackground;

	std::list<Point2d> points_m;
	size_t screenheight_m;
	size_t screenwidth_m;
};

#endif //AREA_H