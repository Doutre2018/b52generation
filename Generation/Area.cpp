#include "Area.h"
#include "Random.h"

Area::Area():area_m{nullptr}, screenheight_m {200}, screenwidth_m{350}
{
	ConsoleContext context(screenwidth_m, screenheight_m, "Guess the best place!", 4, 4, L"Consolas");
	Console::defineContext(context);
}


Area::~Area()
{
}

void Area::generateArea() {
	area_m = &(Console::getInstance().writer().createImage("area"));
	area_m->fill(178, ConsoleColor::bK + ConsoleColor::tb);
	Console::getInstance().writer().push("area");
}

void Area::generatePoint()
{
	for (int i = 0; i < nbPts_m; ++i) {
		points_m.push_back(Point2d(Random::getInstance().uniformRandomize(0, screenwidth_m), Random::getInstance().uniformRandomize(0, screenheight_m)));

	}
}

void Area::showPoint()
{
	
	for (Point2d p : points_m) {
		area_m->drawPoint(p.x(), p.y(), 178, ConsoleColor::bb + ConsoleColor::tw);
	}
	Console::getInstance().writer().push("area");

}
