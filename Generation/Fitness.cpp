#include "Fitness.h"
#include "cmath.h"


void fitnessValue(Shape2D & solutions) {

	int sizeArray = solutions.size();
	for (int i = 0; i < sizeArray; ++i)
	{
		double preFitness{};
		for (int j = 0; j < sizeArray; ++j)
		{
			
			preFitness += square(solutions[i].solution - solutions[j].solution) 

		}
		solutions[i].fitness = sqrt(preFitness / sizeArray);
	}


}











//calcul avec aire et scale_up /scale_down : Solution

//calcul fitness

//elite picked

//injection