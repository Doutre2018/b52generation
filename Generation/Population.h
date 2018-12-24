#ifndef POPULATIONS_H
#define POPULATIONS_H

#include "Shape2D.h"
#include "Console\ConsoleColor.h"
#include "Solution.h"
#include <vector>

class Population
{
public:
	Population(ConsoleColor::Text color);
	~Population();

	Solution & getSolution(size_t i);

	std::vector<Solution>& getListe();

	//Solution randomSolution(size_t size);
	bool isTheSolution();
	void setSolution(size_t i, Solution & sol);
	void setSolutions(std::vector<Solution>& listes, size_t size);
	void populate(std::string type, size_t nbPop, size_t width, size_t height, std::list<Point2d>& points);
	void parentDeath(std::vector<Solution>& childSolution, size_t size);
	ConsoleColor::Text & color();
	int totalFitness(size_t nbPop);

	static void rouletteWheel(std::vector<Solution> listing, int test, std::vector<int> & parentIndex);

	void setElite(size_t i);


private :
	ConsoleColor::Text mColor;

	std::vector<Solution> mSolutions;
	Solution mElite;

};

#endif