#ifndef POPULATIONS_H
#define POPULATIONS_H

#include "Shape2D.h"
#include "Area.h"
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
	Solution randomSolution();
	void setSolution(size_t i, Solution sol);
	void setSolutions(Solution listes[NBPOPULATION]);
	void populate();
	void parentDeath();
private :
	ConsoleColor::Text mColor;
	Solution mSolutions[NBPOPULATION];
};

#endif