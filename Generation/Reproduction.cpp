#include "Reproduction.h"
#include "Transactions.h"
#include "Random.h"
#include "Population.h"
#include "Cercle.h"

Reproduction::Reproduction()
	:mParent1{ 0 },
	mParent2{ 0 },
	mEnfant{ 0 },
	state{StateRep::select},
	mNbChild{0}
{}


Reproduction::~Reproduction()
{
}
Reproduction::StateRep Reproduction::createChild(StateRep & state, Civilisations c, size_t nbPop, std::string type)
{
	
	//select, generatechild, mutate
	switch (state) {
	case StateRep::select:
		if (Transactions::getInstance().conditionselect()) {
			state=  nextState(state);
		}
		else {
			//Je choisie mes 2 prant dans le vecteur de forme je dois en choisir random 2
			int randomParentIndex1 = Random::getInstance().uniformRandomize(1, nbPop -1);
			int randomParentIndex2 = Random::getInstance().uniformRandomize(1, nbPop -1);

			mParent1=c.getPopulation(0).getSolution(randomParentIndex1).shape()->encodePropreties();
			mParent2 = c.getPopulation(0).getSolution(randomParentIndex2).shape()->encodePropreties();
			return state;
		}
		break;
	case StateRep::generatechild:
		if (Transactions::getInstance().conditiongeneratechild()) {
			state = nextState(state);
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
			delivery(type);
			state = StateRep::select;
			mParent1 = 0;
			mParent2 = 0;
			mEnfant = 0;
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


void Reproduction::delivery(std::string type) {
	Shape2D *shape =nullptr;
	if (type == "cercle")
	{
		shape=new Cercle();
		shape->decodePropreties(mEnfant);
	}
	if (shape != nullptr) {
		mChildSolution[mNbChild] = Solution(shape);
		mChildSolution[mNbChild].fitnessEvaluation();
	}
	mNbChild++;
}

Solution * Reproduction::getChildren() {
	return mChildSolution;
}

size_t Reproduction::nbChild() {
	return mNbChild;
}

void Reproduction::setNbChild(size_t nb) {
	mNbChild = nb;
}
