#include "Console\Console.h"
#include "Point2d.h"
#include "Random.h"
#include "Shape2D.h"
#include "Cercle.h"

#define SIZEW 350
#define SIZEH 200

#define NBOBSTACLES 100
#define SHAPE "cercle"

#define NBPOPULATION 100

class Area
{
private:
	Area();
	~Area();
public:
	void generateArea();
	void generatePoint();
	void testArea();
	void showPoint();
	void drawShape(Shape2D ** liste, size_t size, ConsoleColor::Text color);
	static Area& getInstance()
	{
		static Area instance;
		return instance;
	}

	size_t sizeW() { return SIZEW; }
	size_t sizeH() { return SIZEH; }

	size_t nbObstacles() { return NBOBSTACLES; }
	std::string shape() { return SHAPE; }


private :
	ConsoleImage * area_m;
	std::list<Point2d> points_m;
	size_t screenheight_m;
	size_t screenwidth_m;
};

