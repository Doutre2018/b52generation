#ifndef SOLUTION_H
#define SOLUTION_H
#include "Shape2D.h"

class Solution
{
public:
	Solution();
	Solution(Shape2D* shape, size_t width, size_t height, int fitness = 0, double proportionFitness = 0);
	~Solution();

	void deleteShape();
	int fitnessEvaluation(std::list<Point2d> points);
	Shape2D *& shape();

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