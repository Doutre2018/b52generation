#ifndef SOLUTION_H
#define SOLUTION_H
#include "Shape2D.h"
#include "Fitness.h"

class Solution
{
public:
	Solution();

	Solution(Shape2D * shape, size_t width, size_t height, double fitness, double proportionFitness);

	~Solution();

	void initialize(Shape2D* shape, size_t width, size_t height);

	int fitnessEvaluation(std::list<Point2d> points);

	Shape2D * shape();


	static void evalSolutionValue(std::vector<Solution> msolutions, size_t size);
	static void evalFitness(std::vector<Solution> mSolutions, size_t size);

	double aire();
	//Shape2D *& shape();// Shape2D * shape();
	int getFitness();

	void setMFitness(double value);

	void setProportionFitness(double proportionFitness);


private:
	Shape2D* mShape;
	size_t mWidth;
	size_t mHeight;

	double mAire;
	double mFitness;
	double mProportionFitness;

};

#endif //SOLUTION_H;