#include "Fitness.h"
#include "math.h"
#include "Solution.h"
#include "Population.h"


void fitnessValue(Solution mSolutions[100]) {

	int sizeArray = mSolutions.size();
	for (int i = 0; i < sizeArray; ++i)
	{
		double preFitness{};
		for (int j = 0; j < sizeArray; ++j)
		{
			
			preFitness += pow(mSolutions[i]->getArea() - mSolutions[j]->getArea(), 2);

		}

		mSolutions[i]->mFitness = sqrt(preFitness / sizeArray);
	}


}


void fitnessValue(Solution soluce) {

	int sizeArray = (soluce.soluTable)->size();
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



