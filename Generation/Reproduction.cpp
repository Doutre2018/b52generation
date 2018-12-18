#include "Reproduction.h"
#include "Transactions.h"
#include "Random.h"
#include "Population.h"
#include "Civilisations.h"

Reproduction::Reproduction()
	:mParent1{ 0 },
	mParent2{ 0 },
	mEnfant{ 0 },
	state{StateRep::select}
{}


Reproduction::~Reproduction()
{
}
Reproduction::StateRep Reproduction::createChild(StateRep & state)
{
	
	//select, generatechild, mutate
	switch (state) {
	case StateRep::select:
		if (Transactions::getInstance().conditionselect()) {
			state=  nextState(state);
		}
		else {
			//Je choisie mes 2 prant dans le vecteur de forme je dois en choisir random 2
			int randomParentIndex1 = Random::getInstance().uniformRandomize(1, 23); //23est un nombre bidon pour le nombre de forme que nous allons avoir setter
			int randomParentIndex2 = Random::getInstance().uniformRandomize(1, 23); //23est un nombre bidon pour le nombre de forme que nous allons avoir setter

			
			//Shape2D *parent1= 
			mParent1=Civilisations::getInstance().getPopulation(0).getSolution(randomParentIndex1)->encodePropreties();
			mParent2 = Civilisations::getInstance().getPopulation(0).getSolution(randomParentIndex2)->encodePropreties();
			state = state;
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
			mEnfant = mParent1 & mask | mParent2 & ~mask;

			state = state;
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
				//nombre de bit a changer
				int nbBitChange{ 1 };
				//Position aléatoire
				for (int i = 0; i < nbBitChange; ++i)
				{
					int indexAléatoire = Random::getInstance().uniformRandomize(1, 36);
					int maskMutate = 1;
					maskMutate <<= indexAléatoire - 1;
					mEnfant = mEnfant ^ maskMutate;


				}
				
			}

			state = state;
		}
		break;
	}

}
Reproduction::StateRep Reproduction::nextState(StateRep & state) {
	return (StateRep)((int)state + 1);
}

Reproduction::StateRep & Reproduction::getState()
{
	return state;
}

int64_t Reproduction::getParent1()
{
	return mParent1;
}

int64_t Reproduction::getParent2()
{
	return mParent2;
}

int64_t Reproduction::getEnfant()
{
	return mEnfant;
}
