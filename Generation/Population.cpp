#include "Population.h"

#include "Random.h"
#include "Cercle.h"
Population::Population(ConsoleColor::Text color):mColor{color}
{
}

Population::~Population()
{
}

Solution & Population::getSolution(size_t i) {
	return mSolutions[i];
}

Solution* Population::getListe() {
	return mSolutions;
}

Solution Population::randomSolution(size_t size) {
	size_t i = Random::getInstance().uniformRandomize(0, size - 1);
	return mSolutions[i];
}

bool Population::isTheSolution() { //check if solution is good
	return false;
}
void Population::setSolution(size_t i, Solution & sol) {
	mSolutions[i] = sol;
}

void Population::setSolutions(Solution *& listes, size_t size) {
	mSolutions = new Solution[size];
	for (int i = 0; i < size; ++i){
		*(mSolutions + i) = listes[i];
	}
}

void Population::deletePopulation(size_t size) {
	for (int i = 0; i < size; ++i) {
		delete mSolutions[i].shape();
	}
}

void Population::populate(std::string type, size_t nbPop, size_t width, size_t height, std::list<Point2d> & points) {
	mSolutions = new Solution[nbPop];
	for (int i = 0; i < nbPop; ++i) {
		Shape2D* shape{ nullptr };
		if (type == "cercle") {

			shape = new Cercle();
			shape->randomize(width,height);
		}
		//if (shape == "triangle")
		//	Triangle shape;
		//if (shape == "rectangle")
		//	Rectangle shape;
		if(shape != nullptr){
			Solution sol(shape);
			sol.fitnessEvaluation(points);
			mSolutions[i] = sol;
			
		}

	}
}
void Population::parentDeath(Solution *& childSolution, size_t size) {
	for (int i = 0; i < size - 1; ++i) {
		mSolutions[i] = childSolution[i];
	}
}
ConsoleColor::Text & Population::color() {
	return mColor;
}