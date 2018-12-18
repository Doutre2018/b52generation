#pragma once
#include "Shape2D.h"

class Solution
{
public:
	Solution();
	Solution(Shape2D* shape, int fitness = 0);
	~Solution();

	int fitnessEvaluation();
	Shape2D * shape();

private:
	Shape2D* mShape;
	int mFitness;


};

