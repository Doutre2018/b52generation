#include "Fitness.h"
#include "math.h"
#include "Solution.h"
#include "Population.h"


void Fitness::fitnessValue(Solution mSolutions[NBPOPULATION]) {

	int sizeArray = NBPOPULATION;
	for (int i = 0; i < 100; ++i)
	{
		double preFitness{};
		for (int j = 0; j < 100; ++j)
		{
			
			preFitness += pow(mSolutions[i].getMShape()->getArea() - mSolutions[j].getMShape()->getArea(), 2);

		}

		mSolutions[i].setMFitness(sqrt(preFitness / sizeArray));
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


