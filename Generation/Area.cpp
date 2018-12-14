


#include "Area.h"
#include "Console\ConsoleColor.h"
#include "Civilisations.h"

Area::Area():area_m{nullptr}, screenheight_m {SIZEH}, screenwidth_m{SIZEW}
{
	ConsoleContext context(screenwidth_m, screenheight_m, "Guess the best place!", 4, 4, L"Consolas");
	Console::defineContext(context);
}


Area::~Area()
{
}

void Area::generateArea() {
	area_m = &(Console::getInstance().writer().createImage("area"));
}

void Area::generatePoint()
{
	for (int i = 0; i < NBOBSTACLES; ++i) {
		points_m.push_back(Point2d(Random::getInstance().uniformRandomize(0, screenwidth_m), Random::getInstance().uniformRandomize(0, screenheight_m)));

	}
}

void Area::testArea() {
	area_m->fill(178, ConsoleColor::bK + ConsoleColor::tr);
	Console::getInstance().writer().push("area");
}

void Area::showPoint()
{
	area_m->fill(178, ConsoleColor::bk + ConsoleColor::tk);

	for (Point2d p : points_m) {
		area_m->drawPoint(p.x(), p.y(), 178, ConsoleColor::bb + ConsoleColor::tw);
	}
}

void Area::showCivilisations() {
	for (int i = 0; i < Civilisations::getInstance().size();++i) {
		Civilisations::getInstance().getPopulation(i).draw(*area_m);
	}

}

void Area::drawShape(Shape2D** liste, size_t size, ConsoleColor::Text color)
{
	for (int i = 0; i < size; ++i) {
		liste[i]->draw(*area_m, color);
	}
}


std::list<Point2d> Area::points()
{
	return points_m;
}




