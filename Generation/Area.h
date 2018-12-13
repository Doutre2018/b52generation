#include "Console\Console.h"
#include "Point2d.h"
class Area
{
private:
	Area();
	~Area();
public:
	void generateArea();
	void generatePoint();
	void showPoint();
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

