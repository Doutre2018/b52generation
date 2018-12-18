#include "Civilisations.h"


ConsoleColor::Text Civilisations::colors[12]{ ConsoleColor::tb,ConsoleColor::tB,ConsoleColor::tc,ConsoleColor::tC, ConsoleColor::tg, ConsoleColor::tG, ConsoleColor::tm,ConsoleColor::tM,ConsoleColor::tr,ConsoleColor::tR, ConsoleColor::ty,ConsoleColor::tY };

Civilisations::Civilisations()
{
}


Civilisations::~Civilisations()
{
}

void Civilisations::regenerate() {
	size_t mSize = size();
	civilisations_m.clear();
	color = Color::brightblue;
	
	for (int i = 0; i < mSize; ++i) {
		civilisations_m.push_back(Populations(colors[(int)color]));
		nextColor();
	}

}

void Civilisations::reset() {
	size_t mSize = size();
	civilisations_m.clear();
	color = Color::brightblue;

}

void Civilisations::createNewPopulations() {
	
	if (color != Color::yellow) {
		civilisations_m.push_back(Populations(colors[(int)color]));
		nextColor();
	}
	
}

void Civilisations::removeLastPopulations() {

	if (color != Color::brightblue) {
		civilisations_m.pop_back();
		lastColor();
	}

}

void Civilisations::nextColor() {
	color = (Color)((int)color + 1);
}

void Civilisations::lastColor() {
	color = (Color)((int)color - 1);
}

Populations Civilisations::getPopulation(int id)
{
	return civilisations_m.at(id);
}

std::vector<Populations> Civilisations::getAll()
{
	return civilisations_m;
}

size_t Civilisations::size() {
	return civilisations_m.size();
}
