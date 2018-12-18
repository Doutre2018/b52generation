#ifndef POPULATIONS_H
#define POPULATIONS_H

#include "Shape2D.h"
#include "Console\ConsoleColor.h"
#include "Solution.h"

class Population
{
public:
	Population(ConsoleColor::Text color);
	~Population();

	void draw(ConsoleImage & image);

	Solution getSolution(size_t i);

	Solution * getListe();
	Solution randomSolution(size_t size);
	void setSolution(size_t i, Solution sol);
	void setSolutions(Solution * listes, size_t size);
	void populate(std::string type, size_t nbPop);
	void parentDeath();
	ConsoleColor::Text color();
private :
	ConsoleColor::Text mColor;
	Solution * mSolutions;
};

#endif