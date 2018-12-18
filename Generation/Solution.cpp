#include "Solution.h"
#include "Population.h"

Solution::Solution()
{
}



Solution::Solution() {


}

/*
Solution::Solution(Shape2D* shape)
	
=======
Solution::Solution(Shape2D* shape, int fitness)
	:mShape{ shape }
>>>>>>> master
{


}
*/
Solution::~Solution()
{
}
/*
void Solution::createSoluTable(){

	Solution soluce{};


	for (int i = 0; i < 100; ++i)
	{
		soluce.soluTable.push_back(Cercle().randomize);


	}


}*/

void Solution::evalSolutionValue(Shape2D *mSolutions[NBPOPULATION]) {
	
	for (std::vector<Shape2D*>::iterator it = mSolutions->begin(); it != v.end(); ++it) {
		/* std::cout << *it; ... */
	}

}

void Solution::evalFitness() {
	
	Fitness::fitnessValue(Solution soluce);



}
//THIS GOES INTO INJECTION
/*
double Solution::MaxScalingPotential(Shape2D evaluated_form) {
	
	return evaluated_form.area * Solution::scalability;
}
*/

/*


MODIFY ERRORS BEFORE COMMIT


double Solution::scalability(Shape2D evaluated_form) {

	double scaleVariation = 1;
	double modX = evaluated_form.x;
	double modY = evaluated_form.y;
	
	
	scaleVariation = Solution::approximateScaleMod(evaluated_form.closeObstacle, evaluated_form.farPoint);
	
	modX > 0 modX = -modX : modX;
	modY > 0 modY = -modY : modY;
	//translate to scale back to translate...to be continued

	Transform2d::translate(evaluated_form.x, evaluated_form)
	Transform2d::scale(scaleVariation *evaluated_form.x, scaleVariation * evaluated_form.y


}


*/
/*
Étant donné le recours à un cercle englobant on obtient qu'aucune collision n'apparaît du fait de la modification. Conséquemment
des considération de collisions générées ne sont pas considérées.

*/
double Solution::approximateScaleMod(double colliderDistance, double radiusForm) {

	if (radiusForm > 0)
		return 0;
	else
	{
		return (colliderDistance - radiusForm) / radiusForm;
	}

}

/* VOIR JEAN SIMON code collision
bool Solution::collision(Point2d obstacle, Shape2D evaluated_form) {

	double distanceToPosition2{};
	distanceToPosition2 = square(evaluated_form.center().x() - obstacle.x) + square(evaluated_form.center().y() - obstacle.y);  //on va utiliser le carré de la distance, meme ratio généré pour notre scaling, même resultat pour collisions

	if (distanceToPosition2 < square(evaluated_form.farPoint))		//sinon collision nulle assurée
		if (evaluated_form.type  == "circle")
			return true;




			*/
	/*   SECTION YET TO BE CODED (FUNCTION CALLS STILL NOT READY


		else if (evaluated_form.type == form_2)
			return Collision::ComplexCollisionForm2(obstacle, evaluated_form);
		else if (evaluated_form.type == form_3)
			return Collision::ComplexCollisionForm3(obstacle, evaluated_form);
			*/
	
/*
return false;


}
*/
/*


int Solution::fitnessEvaluation()
{
	if (mShape->pointInShape())
		mFitness = 0;

	else
		mFitness = 1;
	return mFitness;
}

<<<<<<< HEAD
	return 0;
}

*/

Shape2D * Solution::shape()
{
	return mShape;
}

