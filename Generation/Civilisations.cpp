#include "Civilisations.h"


ConsoleColor::Text Civilisations::colors[12]{ ConsoleColor::tb,ConsoleColor::tB,ConsoleColor::tc,ConsoleColor::tC, ConsoleColor::tg, ConsoleColor::tG, ConsoleColor::tm,ConsoleColor::tM,ConsoleColor::tr,ConsoleColor::tR, ConsoleColor::ty,ConsoleColor::tY };

Civilisations::Civilisations()
{
}


Civilisations::~Civilisations()
{
}

void Civilisations::createNewPopulations() {
	
	if (color != Color::yellow) {
		civilisations_m.push_back(Populations(colors[(int)color]));
		nextColor();
	}
	
}

void Civilisations::nextColor() {
	color = (Color)((int)color + 1);
}
Populations Civilisations::getPopulation(int id)
{
	return civilisations_m.at(id);
}

std::vector<Populations> Civilisations::getAll()
{
	return civilisations_m;
}
