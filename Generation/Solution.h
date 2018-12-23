#ifndef SOLUTION_H
#define SOLUTION_H
#include "Shape2D.h"
#include "Fitness.h"

class Solution
{
public:
	Solution();
<<<<<<< HEAD
	Solution(Shape2D *& shape, size_t width, size_t height, double fitness=0);
=======
	Solution(Shape2D * shape, size_t width, size_t height, int fitness, double proportionFitness);
>>>>>>> master
	~Solution();

	void initialize(Shape2D* shape, size_t width, size_t height);

	int fitnessEvaluation(std::list<Point2d> points);
<<<<<<< HEAD
=======
	Shape2D * shape();
>>>>>>> master

	static void evalSolutionValue(std::vector<Solution> msolutions, size_t size);
	static void evalFitness(std::vector<Solution> mSolutions, size_t size);

	double aire();
	Shape2D *& shape();// Shape2D * shape();
	int getFitness();
<<<<<<< HEAD
	void setMFitness(double value);
=======
	void setProportionFitness(double proportionFitness);
>>>>>>> master

private:
	Shape2D* mShape;
	size_t mWidth;
	size_t mHeight;
<<<<<<< HEAD
	double mAire;
	double mFitness;



=======
	double mProportionFitness;
>>>>>>> master
};

#endif //SOLUTION_H;