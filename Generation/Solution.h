#pragma once

#include "Point2d.h"
#include "Solution.cpp"
#include "Shape2D.h"
#include "Transform2d.h"
#include <vector>
#include "Cercle.h"
#include "Population.h"

#include "Shape2D.h"
const int NBPOPULATION = 100;

class Solution
{
public:
	Solution();

	//Solution(Shape2D* shape);
	~Solution();

	
	//double MaxScalingPotential(Object* dynamic_cast evaluated_form);
	//double scalability(Shape2D evaluated_form);
	double approximateScaleMod(double colliderDistance, double farPoint);
	//bool collision(Point2d obstacle, Shape2D evaluated_form);
	void evalSolutionValue(Solution msolutions[100]);		//BAD CODE hard coded...
	void createSoluTable();
	void evalSolutionValue(Solution mSolutions[NBPOPULATION]);
	void evalFitness(Solution mSolution[NBPOPULATION]);
	void buildArray(Solution mSolution[NBPOPULATION]);

	Solution(Shape2D* shape, int fitness = 0);
	~Solution();

	int fitnessEvaluation();
	Shape2D * shape();


private:
	Shape2D mShape;
	double mFitness;
	double mAire;


	//const int COHORT_QTY = 100;
	//Cercle solutions[100];				//placeholder hardcoded value : issue with constant int assignment


};

