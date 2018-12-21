#ifndef SOLUTION_H
#define SOLUTION_H
#include "Shape2D.h"
#include "Fitness.h"

class Solution
{
public:
	Solution();
	Solution(Shape2D* shape, int fitness = 0);
	~Solution();

	int fitnessEvaluation(std::list<Point2d> points);
	static void evalSolutionValue(Solution msolutions[], size_t size);
	static void evalFitness(Solution * mSolutions);
	double aire();
	Shape2D * shape();
	void setMFitness(double value);

private:
	Shape2D* mShape;
	
	double mAire;
	double mFitness;
};

#endif //SOLUTION_H