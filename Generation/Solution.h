#ifndef SOLUTION_H
#define SOLUTION_H
#include "Shape2D.h"

class Solution
{
public:
	Solution();
	Solution(Shape2D * shape, size_t width, size_t height, int fitness, double proportionFitness);
	~Solution();

	void initialize(Shape2D* shape, size_t width, size_t height);

	int fitnessEvaluation(std::list<Point2d> points);
	Shape2D * shape();

	int getFitness();
	void setProportionFitness(double proportionFitness);

private:
	Shape2D* mShape;
	int mFitness;
	size_t mWidth;
	size_t mHeight;
	double mProportionFitness;
};

#endif //SOLUTION_H