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

	Shape2D * getSolutions(size_t i);

private :
	ConsoleColor::Text mColor;
	Shape2D *mSolutions[NBPOPULATION];
};

#endif