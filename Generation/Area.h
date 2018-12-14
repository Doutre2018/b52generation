#include "Console\Console.h"
#include "Point2d.h"
#include "Random.h"
#include "Shape2D.h"
#include "Cercle.h"

typedef std::list<Shape2D*> shapeList_t;

class Area
{
private:
	Area();
	~Area();
public:
	void generateArea();
	void generatePoint();
	void showPoint();
	void drawCercle(std::list<Cercle> liste);
	void drawShape(shapeList_t liste);
	static Area& getInstance()
	{
		static Area instance;
		return instance;
	}
private :
	ConsoleImage * area_m;
	std::list<Point2d> points_m;
	size_t const nbPts_m = 100;
	size_t screenheight_m;
	size_t screenwidth_m;
};

