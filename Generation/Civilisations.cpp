#include "Civilisations.h"


ConsoleColor::Text Civilisations::colors[12]{ ConsoleColor::tb,ConsoleColor::tB,ConsoleColor::tc,ConsoleColor::tC, ConsoleColor::tg, ConsoleColor::tG, ConsoleColor::tm,ConsoleColor::tM,ConsoleColor::tr,ConsoleColor::tR, ConsoleColor::ty,ConsoleColor::tY };

void Civilisations::regenerate(std::string type, size_t nbShape, size_t width, size_t height) {
	size_t mSize = size();
	civilisations_m.clear();
	color = Color::brightblue;
	for (int i = 0; i < mSize; ++i) {
		civilisations_m.push_back(Population(colors[(int)color]));
		civilisations_m[i].populate(type, nbShape, width,height);
		nextColor();
	}
}

void Civilisations::reset() {
	size_t mSize = size();
	civilisations_m.clear();
	color = Color::brightblue;
}

size_t Civilisations::nbPopulations() {
	return civilisations_m.size();
}
void Civilisations::createNewPopulations() {
	if (color != Color::yellow) {
		civilisations_m.push_back(Population(colors[(int)color]));
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

Population & Civilisations::getPopulation(int id){
	return civilisations_m.at(id);
}

std::vector<Population> & Civilisations::getAll(){
	return civilisations_m;
}

size_t Civilisations::size() {
	return civilisations_m.size();
}
