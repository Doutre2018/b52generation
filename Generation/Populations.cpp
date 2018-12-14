#include "Populations.h"


Populations::Populations(ConsoleColor::Text color):
mColor{color}
{

<<<<<<< HEAD
=======
	for (int i = 0; i < NBPOPULATION; ++i) {
		int x = Random::getInstance().uniformRandomize(0, SIZEW);
		int y = Random::getInstance().uniformRandomize(0, SIZEH);
		size_t radius = Random::getInstance().uniformRandomize(0, SIZEH);
		mListe[i] = new Cercle(Point2d(x, y), radius);
		
	}
>>>>>>> 7a46d96171c7fdef976a9061ce9527443c875e7c

	Area::getInstance().drawShape(mListe, NBPOPULATION, mColor);
}

Populations::~Populations()
{
}

void Populations::draw(ConsoleImage & image) {
	Area::getInstance().drawShape(mListe, NBPOPULATION, mColor);
}