#pragma once

#include "Point2d.h"
#include "Solution.cpp"
#include "Shape2D.h"
#include "Transform2d.h"
#include <vector>

#include "Shape2D.h"


class Solution
{
public:
	Solution(Shape2D* shape);
	~Solution();

	
	double MaxScalingPotential(Shape2D evaluated_form);
	double scalability(Shape2D evaluated_form);
	double approximateScaleMod(double colliderDistance, double farPoint);
	bool collision(Point2d obstacle, Shape2D evaluated_form);

	int fitnessEvaluation();

private:
	Shape2D* mShape;
	int mFitness;



};

