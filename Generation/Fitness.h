#pragma once
#include "Shape2D.h"
class Solution;
#define NBPOPULATION 100

class Fitness {

public:
	static void fitnessValue(std::vector<Solution> mSolutions, size_t size); //array filled with all shapes from a cohort 


private:
	double mFitValue;


};