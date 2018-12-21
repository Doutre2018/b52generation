#include "Solution.h"
#include "Area.h"

Solution::Solution()
	:mShape{ nullptr },
	mWidth{ 0 },
	mHeight{ 0 },
	mFitness{ 0 }
{
}

Solution::Solution(Shape2D* shape, size_t width, size_t height, int fitness, double proportionFitness)
	:mShape{ shape },
	mWidth{ width },
	mHeight{ height },
	mFitness{fitness}
{
}

Solution::~Solution()
{
	delete mShape;
}

void Solution::initialize(Shape2D * shape, size_t width, size_t height) {
	delete mShape;
	mShape = shape;
	mWidth = width;
	mHeight = height;
	mFitness = 0;
}

int Solution::fitnessEvaluation(std::list<Point2d> points)
{
	mFitness = mShape->borderProximity(mWidth, mHeight);
	//mFitness *= mShape->pointInShape(points);
	return mFitness; 
}

Shape2D * Solution::shape()
{
	return mShape;
}

int Solution::getFitness()
{
	return mFitness;
}

void Solution::setProportionFitness(double proportionFitness)
{
	mProportionFitness = proportionFitness;
}
