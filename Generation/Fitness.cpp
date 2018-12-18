#include "Fitness.h"
#include "math.h"


void fitnessValue(Shape2D & solutions) {

	int sizeArray = solutions.size();
	for (int i = 0; i < sizeArray; ++i)
	{
		double preFitness{};
		for (int j = 0; j < sizeArray; ++j)
		{
			
			preFitness += pow(solutions[i].solution - solutions[j].solution, 2) 

		}
		solutions[i].fitness = sqrt(preFitness / sizeArray);
	}


}




