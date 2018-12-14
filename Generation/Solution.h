#pragma once
#include "Shape2D.h"

class Solution
{
public:
	Solution(Shape2D* shape);
	~Solution();

	int fitnessEvaluation();

private:
	Shape2D* mShape;
	int mFitness;


};

