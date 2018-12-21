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
	return mSolutions.at(i);
}

std::vector<Solution> & Population::getListe() {
	return mSolutions;
}

Solution Population::randomSolution(size_t size) {
	size_t i = Random::getInstance().uniformRandomize(0, size - 1);
	return mSolutions.at(i);
}

bool Population::isTheSolution() { //check if solution is good
	return false;
}
void Population::setSolution(size_t i, Solution & sol) {
	mSolutions.at(i) = sol;
}

void Population::setSolutions(std::vector<Solution> & listes, size_t size) {
	
	mSolutions = listes;
	for (int i = 0; i < size; ++i){
		mSolutions.at(i) = listes.at(i);
	}
}

void Population::populate(std::string type, size_t nbPop, size_t width, size_t height, std::list<Point2d> & points) {
	mSolutions.clear();
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
			mSolutions.push_back(Solution(shape, width, height));
			
		}

	}
}
void Population::parentDeath(std::vector<Solution> & childSolution, size_t size) {
	for (int i = 0; i < size - 1; ++i) {
		mSolutions.at(i) = childSolution.at(i);
	}
}
ConsoleColor::Text & Population::color() {
	return mColor;
}

int Population::totalFitness(size_t nbPop)
{
	int total{ 0 };
	for (int i{ 0 }; i < nbPop; ++i)
	{
		Solution* a = &mSolutions.at(i);
		total += a->getFitness();
	}
	return total;
}

void Population::rouletteWheel()
{
}
