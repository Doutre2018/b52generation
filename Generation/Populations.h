#ifndef POPULATIONS_H
#define POPULATIONS_H

#include "Shape2D.h"
#include "Area.h"
#include "Console\ConsoleColor.h"

class Populations
{
public:
	Populations(ConsoleColor::Text color);
	~Populations();

	void draw(ConsoleImage & image);
	Shape2D * getShape(int index);

private :
	ConsoleColor::Text mColor;
	Shape2D *mListe[NBPOPULATION];
};

#endif