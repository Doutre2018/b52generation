#include "Populations.h"


Populations::Populations(ConsoleColor::Text color):
mColor{color}
{
	if (Area::getInstance().shape_g == "cercle") {
		for (int i = 0; i < NBPOPULATION; ++i) {
			mListe[i] = new Cercle();
			mListe[i]->randomize();

		}
	}
	else if (Area::getInstance().shape_g == "triangle") {
		for (int i = 0; i < NBPOPULATION; ++i) {
			//mListe[i] = new Triangle();
			//mListe[i]->randomize();

		}
	}
	else {
		for (int i = 0; i < NBPOPULATION; ++i) {
			//mListe[i] = new Rectangle();
			//mListe[i]->randomize();

		}
	}
	
}

Populations::~Populations()
{
}

void Populations::draw(ConsoleImage & image) {
	Area::getInstance().drawShape(mListe, NBPOPULATION, mColor);
}