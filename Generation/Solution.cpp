#include "Solution.h"
#include "Area.h"

Solution::Solution()
	:mShape{ nullptr },
	mWidth{ 0 },
	mHeight{ 0 },
	mFitness{ 0 }
{
}


Solution::Solution(Shape2D* shape, size_t width, size_t height, double fitness, double proportionFitness)

	:mShape{ shape },
	mWidth{ width },
	mHeight{ height },
	mFitness{fitness}
{
}

Solution::~Solution()
{
	//delete mShape;
}
void Solution::evalFitness(std::vector<Solution> mSolutions, size_t size) {


	Fitness::fitnessValue(mSolutions, size);
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
	mFitness *= mShape->pointInShape(points);
	if (mShape->outOfBounds(mWidth, mHeight)) {
		mFitness *= 0.01;
	}

	
	return mFitness; 
}

Shape2D * Solution::shape()
{
	return mShape;
}


void Solution::evalSolutionValue(std::vector<Solution> mSolutions, size_t size) {

	for (int i = 0; i < size; ++i)
	{
		mSolutions[i].mAire = (mSolutions[i].mShape->calculateArea());


	}

}


double Solution::aire() {
	return mAire;


}

void Solution::setMFitness(double value) {

	if (value >= 0 || value < 900)
		mFitness = value;
	else
		mFitness = 335;


}

int Solution::getFitness()
{
	return mFitness;
}


void Solution::setProportionFitness(double proportionFitness)
{
	mProportionFitness = proportionFitness;
}

