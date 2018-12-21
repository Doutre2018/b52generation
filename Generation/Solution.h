#ifndef SOLUTION_H
#define SOLUTION_H
#include "Shape2D.h"
#include "Fitness.h"

class Solution
{
public:
	Solution();
	Solution(Shape2D *& shape, size_t width, size_t height, double fitness=0);
	~Solution();

	void deleteShape();

	int fitnessEvaluation(std::list<Point2d> points);

	static void evalSolutionValue(std::vector<Solution> msolutions, size_t size);
	static void evalFitness(std::vector<Solution> mSolutions, size_t size);

	double aire();
	Shape2D *& shape();// Shape2D * shape();
	int getFitness();
	void setMFitness(double value);

private:
	Shape2D* mShape;
	size_t mWidth;
	size_t mHeight;
	double mAire;
	double mFitness;



};

#endif //SOLUTION_H;