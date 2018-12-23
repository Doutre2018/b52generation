#include "Solution.h"
#include "Area.h"

Solution::Solution()
	:mShape{ nullptr },
	mWidth{ 0 },
	mHeight{ 0 },
	mFitness{ 0 }
{
}

<<<<<<< HEAD
Solution::Solution(Shape2D*& shape, size_t width, size_t height, double fitness)

=======
Solution::Solution(Shape2D* shape, size_t width, size_t height, int fitness, double proportionFitness)
>>>>>>> master
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
void Solution::evalFitness(std::vector<Solution> mSolutions, size_t size) {


	Fitness::fitnessValue(mSolutions, size);
}


void Solution::initialize(Shape2D * shape, size_t width, size_t height) {
	delete mShape;
<<<<<<< HEAD

=======
	mShape = shape;
	mWidth = width;
	mHeight = height;
	mFitness = 0;
>>>>>>> master
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

	mFitness = (double) value;


}

int Solution::getFitness()
{
	return mFitness;
}

<<<<<<< HEAD
=======
void Solution::setProportionFitness(double proportionFitness)
{
	mProportionFitness = proportionFitness;
}
>>>>>>> master
