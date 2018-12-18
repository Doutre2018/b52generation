#include "Population.h"


Population::Population(ConsoleColor::Text color):
mColor{color}
{
	populate();
	
}

Population::~Population()
{
}

void Population::draw(ConsoleImage & image) {
	Area::getInstance().drawShape(mSolutions, NBPOPULATION, mColor);
}

Solution * Population::getSolution(size_t i) {
	return mSolutions[i];
}

Solution** Population::getListe() {
	return mSolutions;
}

Solution * Population::randomSolution() {
	size_t i = Random::getInstance().uniformRandomize(0, NBPOPULATION - 1);
	return mSolutions[i];
}

void Population::setSolution(size_t i, Solution * shape) {
	mSolutions[i] = shape;
}

void Population::setSolutions(Solution * listes[NBPOPULATION]) {
	for (int i = 0; i < NBPOPULATION; ++i){
		mSolutions[i] = listes[i];
	}
}

void Population::populate() {
	for (int i = 0; i < NBPOPULATION; ++i) {
		Shape2D* shape;
		if (SHAPE == "cercle")
			shape = new Cercle();
		//if (shape == "triangle")
		//	Triangle shape;
		//if (shape == "rectangle")
		//	Rectangle shape;
		if(shape != NULL){
			shape->randomize();
			Solution sol(shape);
			sol.fitnessEvaluation();
			mSolutions[i] = &sol;
		}

	}
}