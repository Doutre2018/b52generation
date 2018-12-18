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

Shape2D * Population::getSolution(size_t i) {
	return mSolutions[i];
}

Shape2D** Population::getListe() {
	return mSolutions;
}

Shape2D * Population::randomSolution() {
	size_t i = Random::getInstance().uniformRandomize(0, NBPOPULATION - 1);
	return mSolutions[i];
}

void * Population::setSolution(size_t i, Shape2D * shape) {
	mSolutions[i] = shape;
}

void * Population::setSolutions(Shape2D * listes[NBPOPULATION]) {
	for (int i = 0; i < NBPOPULATION; ++i){
		mSolutions[i] = listes[i];
	}
}