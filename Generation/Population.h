#ifndef POPULATIONS_H
#define POPULATIONS_H

#include "Shape2D.h"
#include "Area.h"
#include "Console\ConsoleColor.h"

class Population
{
public:
	Population(ConsoleColor::Text color);
	~Population();

	void draw(ConsoleImage & image);

	Shape2D * getSolution(size_t i);

	Shape2D ** getListe();
	Shape2D * randomSolution();
	void * setSolution(size_t i, Shape2D * shape);
	void * setSolutions(Shape2D * listes[NBPOPULATION]);
private :
	ConsoleColor::Text mColor;
	Shape2D *mSolutions[NBPOPULATION];
};

#endif