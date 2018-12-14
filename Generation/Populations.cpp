#include "Populations.h"


Populations::Populations(ConsoleColor::Text color):
mColor{color}
{
	for (int i = 0; i < NBPOPULATION; ++i) {
		mListe[i] = new Cercle();
		mListe[i]->randomize();
		
	}
}

Populations::~Populations()
{
}

void Populations::draw(ConsoleImage & image) {
	Area::getInstance().drawShape(mListe, NBPOPULATION, mColor);
}