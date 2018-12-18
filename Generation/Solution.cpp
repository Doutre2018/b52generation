#include "Solution.h"

Solution::Solution()
{
}

Solution::Solution(Shape2D* shape, int fitness)
	:mShape{ shape }
{
}

Solution::~Solution()
{
}



int Solution::fitnessEvaluation(std::list<Point2d> points)
{
	if (mShape->pointInShape(points))
		mFitness = 0;

	else
		mFitness = 1;
	return mFitness;
}

Shape2D * Solution::shape()
{
	return mShape;
}
