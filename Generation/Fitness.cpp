#include "Fitness.h"
#include "math.h"
#include "Solution.h"
#include "Population.h"


void Fitness::fitnessValue(Solution * mSolutions) {

	int sizeArray = NBPOPULATION;
	double fit_value;
	double distanceCollider;
	


	for (int i = 0; i < 100; ++i)
	{
		double preFitness{};
		for (int j = 0; j < 100; ++j)
		{

			preFitness += pow(mSolutions[i].aire() - mSolutions[j].aire(), 2);

		}
		fit_value = sqrt(preFitness / sizeArray);
		fit_value = 1 / fit_value;

		/*
		Point2d pt = 
		
		distanceCollider = (mSolutions[i].mShape->mNearestPoint).distance2(mSolutions[i].mShape->mPoint);
		fit_value = (distanceCollider / mSolutions[i].mShape->mRadius);
		*/
		mSolutions[i].setMFitness(fit_value);
		
		
	}


}

/*
void fitnessValue(Solution soluce) {

int sizeArray = NBPOPULATION;


for (int i = 0; i < sizeArray; ++i)
{
double preFitness{};
for (int j = 0; j < sizeArray; ++j)
{

preFitness += pow(soluce.soluTable[i]->getArea() - soluce.soluTable[j]->getArea(), 2);

}

soluce.soluTable[i]->mFitness = sqrt(preFitness / sizeArray);
}


}


*/
