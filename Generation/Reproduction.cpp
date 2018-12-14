#include "Reproduction.h"
#include "Transactions.h"
#include "Random.h"
Reproduction::Reproduction()
{
}


Reproduction::~Reproduction()
{
}

Reproduction::StateRep Reproduction::createChild(StateRep & state)
{
	
	//select, generatechild, mutate
	switch (state) {
	case StateRep::select:
		if (Transactions::getInstance().conditionselect()) {
			return nextState(state);
		}
		else {

			//Je choisie mes 2 prant dans le vecteur de forme je dois en choisir random 2
			int randomParentIndex1 = Random::getInstance().uniformRandomize(1, 23); //23est un nombre bidon pour le nombre de forme que nous allons avoir setter
			int randomParentIndex2 = Random::getInstance().uniformRandomize(1, 23); //23est un nombre bidon pour le nombre de forme que nous allons avoir setter

			//parent1= ArrayForme[randomParentIndex1] ;
			//parent1= ArrayForme[randomParentIndex1] ;

			return state;
		}
		break;
	case StateRep::generatechild:
		if (Transactions::getInstance().conditiongeneratechild()) {
			return nextState(state);
		}
		else {
			//Je prend mes 2 parents
			//Je choisie le randomize de la coupure
			int indexSplit = Random::getInstance().uniformRandomize(1, 36);
			int mask{ (int)pow(2,indexSplit) - 1 };
			//Je realise l'enfant
			binaireEnfant = parent1 & mask | parent2 & ~mask;

			return state;
		}
		break;
	case StateRep::mutate:
		if (Transactions::getInstance().conditionmutate()) {
			return StateRep::select;
		}
		else {
			//Es ce que je fait un mutant ou pas

			if (int a = Random::getInstance().uniformRandomize(1, 100) <= percentageMutate)
			{
				
			}

			return state;
		}
		break;
	}

}
Reproduction::StateRep Reproduction::nextState(StateRep & state) {
	return (StateRep)((int)state + 1);
}