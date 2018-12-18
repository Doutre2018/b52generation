#ifndef SOLUTION_H
#define SOLUTION_H
#include "Shape2D.h"

class Solution
{
public:
	Solution();
	Solution(Shape2D* shape, int fitness = 0);
	~Solution();

	int fitnessEvaluation();
	Shape2D * shape();

private:
	Shape2D* mShape;
	int mFitness;
};

#endif //SOLUTION_H