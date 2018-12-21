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
void Solution::evalFitness(Solution * mSolutions) {

	Fitness::fitnessValue(mSolutions);


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

void Solution::evalSolutionValue(Solution mSolutions[], size_t size) {

	for (int i = 0; i < size; ++i)
	{
		mSolutions[i].mAire = (mSolutions[i].mShape->calculateArea());


	}

}


double Solution::aire() {
	return mAire;


}

void Solution::setMFitness(double value) {

	mFitness = (double) value;


}