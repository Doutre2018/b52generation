#include "Solution.h"



Solution::Solution(Shape2D* shape)
	:mShape{ shape }
{
}

Solution::~Solution()
{
}



int Solution::fitnessEvaluation()
{
	
	if (mShape->pointInShape())
		return 0;

	else
		return 1;
	
}