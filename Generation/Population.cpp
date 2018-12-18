#include "Population.h"


Population::Population(ConsoleColor::Text color):
mColor{color}
{
	if (Area::getInstance().shape_g == "cercle") {
		for (int i = 0; i < NBPOPULATION; ++i) {
			mSolutions[i] = new Cercle();
			mSolutions[i]->randomize();

		}
	}
	else if (Area::getInstance().shape_g == "triangle") {
		for (int i = 0; i < NBPOPULATION; ++i) {
			//mSolutions[i] = new Triangle();
			//mSolutions[i]->randomize();

		}
	}
	else {
		for (int i = 0; i < NBPOPULATION; ++i) {
			//mSolutions[i] = new Rectangle();
			//mSolutions[i]->randomize();

		}
	}
	
}

Population::~Population()
{
}

void Population::draw(ConsoleImage & image) {
	Area::getInstance().drawShape(mSolutions, NBPOPULATION, mColor);
}