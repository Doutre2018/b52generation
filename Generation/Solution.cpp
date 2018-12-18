#include "Solution.h"



Solution::Solution(Shape2D* shape, int fitness)
	:mShape{ shape }
{
}

Solution::~Solution()
{
}



int Solution::fitnessEvaluation()
{
	if (mShape->pointInShape())
		mFitness = 0;

	else
		mFitness = 1;
	return mFitness;
}

Shape2D * Solution::shape()
{
	return mShape;
}
