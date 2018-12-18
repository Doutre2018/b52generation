//include self
#include "Area.h"

//include de la team
#include "Civilisations.h"
#include "Cercle.h"
#include "Shape2D.h"
#include "Point2d.h"
#include "Random.h"

Area::Area(size_t height, size_t width):area_m{nullptr}, mScreenWidth { width }, mScreenHeight{height }{
	
}

Area::~Area(){
}

void Area::generateArea() {
	ConsoleContext context(mScreenWidth, mScreenHeight , "Guess the best place!", 4, 4, L"Consolas");
	Console::defineContext(context);
	area_m = &(Console::getInstance().writer().createImage("area"));
}

void Area::generatePoint(size_t nbObstacles){
	for (int i = 0; i < nbObstacles; ++i) {
		points_m.push_back(Point2d(Random::getInstance().uniformRandomize(0, mScreenWidth), Random::getInstance().uniformRandomize(0, mScreenHeight )));
	}
}

void Area::testArea() {
	area_m->fill(178, ConsoleColor::bK + ConsoleColor::tr);
	Console::getInstance().writer().push("area");
}

void Area::showPoint(){
	area_m->fill(178, ConsoleColor::bk + ConsoleColor::tk);
	for (Point2d p : points_m) {
		area_m->drawPoint(p.x(), p.y(), 178, ConsoleColor::bb + ConsoleColor::tw);
	}
}

void Area::showCivilisations(std::vector<Population> & populations, size_t size) {
	for (Population& p : populations) {
		drawShape(p.getListe(), size, p.color());
	}
}

void Area::drawShape(Solution* liste, size_t size, ConsoleColor::Text color){
	for (int i = 0; i < size-1; ++i) {
		liste[i].shape()->draw(*area_m, color);
	}
}

std::list<Point2d> Area::points(){
	return points_m;
}




