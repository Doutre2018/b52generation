#ifndef AREA_H
#define AREA_H

//include les objets Consoles
#include "Console\Console.h"
#include "Console\ConsoleColor.h"

//include de la Team
#include "Solution.h"

class Area
{
private:
	Area(size_t height, size_t width);
	~Area();
public:
	void generateArea();
	void generatePoint(size_t nbObstacles);
	void testArea();
	void showPoint();
	void showCivilisations();
	void drawShape(Solution * liste, size_t size, ConsoleColor::Text color);

	std::list<Point2d> points();
private :
	ConsoleImage * area_m;
	ConsoleImage * mBackground;

	std::list<Point2d> points_m;
	size_t screenheight_m;
	size_t screenwidth_m;
};

#endif //AREA_H