#include "Population.h"

#include "Random.h"
#include "Cercle.h"
Population::Population(ConsoleColor::Text color):mColor{color}
{populate();	
}

Population::~Population()
{
}

Solution Population::getSolution(size_t i) {
	return mSolutions[i];
}

Solution* Population::getListe() {
	return mSolutions;
}

Solution Population::randomSolution(size_t size) {
	size_t i = Random::getInstance().uniformRandomize(0, size - 1);
	return mSolutions[i];
}

void Population::setSolution(size_t i, Solution sol) {
	mSolutions[i] = sol;
}

void Population::setSolutions(Solution * listes, size_t size) {
	for (int i = 0; i < size; ++i){
		mSolutions[i] = listes[i];
	}
}

void Population::populate(std::string type, size_t nbPop) {
	for (int i = 0; i < nbPop - 1; ++i) {
		Shape2D* shape{ nullptr };
		if (type == "cercle") {
			shape = new Cercle();
			shape->randomize();
		}
		//if (shape == "triangle")
		//	Triangle shape;
		//if (shape == "rectangle")
		//	Rectangle shape;
		if(shape != nullptr){
			Solution sol(shape);
			sol.fitnessEvaluation();
			mSolutions[i] = sol;
		}

	}
}
void Population::parentDeath() {
	Solution * children = Reproduction::getInstance().getChildren();
	for (int i = 0; i < NBPOPULATION - 1; ++i) {
		mSolutions[i] = children[i];
		//Area::getInstance().drawShape(children, NBPOPULATION, ConsoleColor::tm);
	}
}
ConsoleColor::Text Population::color() {
	return mColor;
}