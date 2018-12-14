#include "Populations.h"
#include "Shape2D.h"
#include "Area.h"

Populations::Populations(ConsoleColor::Text color)
{
	Shape2D *liste[NBPOPULATION];


	Area::getInstance().drawShape(liste, NBPOPULATION, color);
}

Populations::~Populations()
{
}
