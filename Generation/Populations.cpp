#include "Populations.h"
#include "Shape2D.h"
#include "Area.h"

Populations::Populations(ConsoleColor::Text color)
{
	Shape2D *liste[NBPOPULATION];

	for (int i = 0; i < NBPOPULATION; ++i) {
		int x = Random::getInstance().uniformRandomize(0, SIZEW);
		int y = Random::getInstance().uniformRandomize(0, SIZEH);
		size_t radius = Random::getInstance().uniformRandomize(0, SIZEH);
		liste[i] = new Cercle(Point2d(x, y), radius);
		
	}

	Area::getInstance().drawShape(liste, NBPOPULATION, color);
}

Populations::~Populations()
{
}
