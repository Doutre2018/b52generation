#include "Populations.h"
#include "Civilisations.h"
#include "Civilisations.h"

Populations::Populations(ConsoleColor::Text color):
mColor{color}
{
	for (int i = 0; i < NBPOPULATION; ++i) {
		int x = Random::getInstance().uniformRandomize(0, SIZEW);
		int y = Random::getInstance().uniformRandomize(0, SIZEH);
		size_t radius = Random::getInstance().uniformRandomize(0, SIZEH);
		mListe[i] = new Cercle(Point2d(x, y), radius);
		
	}
}

Populations::~Populations()
{
}

void Populations::draw(ConsoleImage & image) {
	Area::getInstance().drawShape(mListe, NBPOPULATION, mColor);
}

Shape2D* Populations::getShape(int index)
{
	return mListe[index];;
}
