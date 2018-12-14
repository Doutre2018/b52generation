#pragma once
#include "Point2d.h"
#include "Solution.cpp"
#include "Shape2D.h"
#include "Transform2d.h"
#include <vector>

class Solution
{
public:
	Solution();
	~Solution();

	
	double MaxScalingPotential(Shape2D evaluated_form);
	double scalability(Shape2D evaluated_form);
	double approximateScaleMod(double colliderDistance, double farPoint);
	bool collision(Point2d obstacle, Shape2D evaluated_form);


};

