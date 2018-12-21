#include "Solution.h"
#include "Area.h"

Solution::Solution()
{
}

Solution::Solution(Shape2D*& shape, size_t width, size_t height, int fitness)
	:mShape{ shape },
	mWidth{ width },
	mHeight{ height }
{
}

Solution::~Solution()
{
}



int Solution::fitnessEvaluation(std::list<Point2d> points)
{
	mFitness = mShape->borderProximity(mWidth, mHeight);
	mFitness *= mShape->pointInShape(points);
	return mFitness;
}

Shape2D *& Solution::shape()
{
	return mShape;
}

int Solution::getFitness()
{
	return mFitness;
}
