#include "Population.h"
#include <iostream>
#include "Random.h"
#include "Cercle.h"
<<<<<<< HEAD
#include "debugstream.h"
#include "Mathematical.h"



Population::Population(ConsoleColor::Text color):mColor{color}
=======
#include "Rectangle.h"

Population::Population(ConsoleColor::Text color)
	:mColor{ color }
>>>>>>> master
{
}

Population::~Population()
{
}

Solution & Population::getSolution(size_t i) {
	return mSolutions.at(i);
}
void Population::setElite(size_t i) {
	mElite = getSolution(i);
}
std::vector<Solution> & Population::getListe() {
	return mSolutions;
}
void Population::setSolution(size_t i, Solution & sol) {
	mSolutions.at(i) = sol;
}

void Population::setSolutions(std::vector<Solution> & listes, size_t size) {
	
	mSolutions = listes;
	for (int i = 0; i < size; ++i) {
		mSolutions.at(i) = listes.at(i);
	}
	
	
}

void Population::populate(std::string type, size_t nbPop, size_t width, size_t height, std::list<Point2d> & points) {
	mSolutions.resize(nbPop);
	for (int i = 0; i < nbPop; ++i) {
		Shape2D* shape{ nullptr };
		if (type == "cercle") {
			shape = new Cercle();
			shape->randomize(width,height);
		} else 	if (type == "rectangle") {
			//shape = new Rectangle();
			//shape->randomize(width, height);
		}
		//if (shape == "triangle")
		//	Triangle shape;
		//if (shape == "rectangle")
		//	Rectangle shape;
		if(shape != nullptr){
			mSolutions[i].initialize(shape, width, height);
		}
	}
}
void Population::parentDeath(std::vector<Solution> & childSolution, size_t size) {
	mSolutions.swap(childSolution);
	childSolution.clear();
	childSolution.resize(size);

	//for (int i = 0; i < size - 1; ++i) {
		//mSolutions.at(i) = childSolution.at(i);
	//}
}
ConsoleColor::Text & Population::color() {
	return mColor;
}

int Population::totalFitness(size_t nbPop)
{
	int total{ 0 };
	

	for (int i{ 0 }; i < nbPop; ++i)
	{
		Solution * a = &mSolutions.at(i);
		total += a->getFitness();
	}
	return total;
}

<<<<<<< HEAD
void Population::rouletteWheel(std::vector<Solution> listing, int test, std::vector<int> parentIndex)
{
	const int sizeArray = listing.size() * 2;
	
	int targetIndex{};
	int totalFitness{};
	Solution temp;
	
	
	Mathematical::sortThing(listing); // sort de la liste de solutions 
	

	for (int i = 0; i < listing.size(); i++)
		debug() << listing.at(i).getFitness();
	
	int format = listing.size() % 2 == 0 ? listing.size() / 2 - 1 : listing.size() / 2; //reverse the ascending sort

	for (int i = 0; i < format; ++i)
	{
		temp = listing.at(i);
		listing.at(i) = listing.at(format - i);
		listing.at(format - i) = temp;
	}


	for (int i = 0; i < listing.size(); i++)
		debug() << listing.at(i).getFitness();

	/*
	

	for (int i = 0; i < sizeArray; ++i)
	{
		targetIndex = Random::getInstance().uniformRandomize(1, test - 1);
		int j = 0;

		while (targetIndex > listing.at(j).getFitness() + totalFitness && j < 100)
		{
			totalFitness += listing.at(j).getFitness();
			++j;
		}
		parentIndex.at(i) = j;
		targetIndex = 0;
	}


	*/
	
	
=======
Solution & Population::rouletteWheel(size_t nbPop)
{
	int totFitness{ totalFitness(nbPop) };
	int randomNumber{ Random::getInstance().uniformRandomize(1, totFitness) };

	int counter{ 0 };

	while(randomNumber > 0)
	{ 
		randomNumber -= mSolutions.at(counter).getFitness();
		++counter;
	}

	return  mSolutions.at(counter - 1);



	//for (int i{ 0 }; i < nbPop; ++i)
	//{
	//	Solution a = mSolutions[i];
	//	double prop = a.getFitness() / totFitness;
	//	a.setProportionFitness(prop);
	//}
>>>>>>> master
}
