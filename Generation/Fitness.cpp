#include "Fitness.h"
#include "math.h"
#include "Solution.h"


void fitnessValue(std::vector<Shape2D*> soluTable) {

	int sizeArray = soluTable.size();
	for (int i = 0; i < sizeArray; ++i)
	{
		double preFitness{};
		for (int j = 0; j < sizeArray; ++j)
		{
			
			preFitness += pow(soluTable[i]->getArea() - soluTable[j]->getArea(), 2);

		}

		soluTable[i]->mFitness = sqrt(preFitness / sizeArray);
	}


}


void fitnessValue(Solution soluce) {

	int sizeArray = soluce.soluTable->size();
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



