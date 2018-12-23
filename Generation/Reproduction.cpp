#include "Reproduction.h"
#include "Random.h"
#include "Population.h"
#include "Cercle.h"
#include "Rectangle.h"

Reproduction::Reproduction(size_t nbPop, size_t width, size_t mHeight)
	:mParent1{ 0 },
	mParent2{ 0 },
	mEnfant{ 0 },
	mNbChild{0}
{
	mChildSolution.resize(nbPop);
}


Reproduction::~Reproduction()
{
}

void Reproduction::createChild( Civilisations & c, size_t nbPop, size_t nbCivilisations, std::string type)
{
	int randomParentIndex1, randomParentIndex2, mask, indexSplit;

	int test = c.getPopulation(0).totalFitness(nbPop);
	std::vector<int> parentIndex(200);
	std::vector<Solution> listing;

	

	for (int i = 0; i < nbCivilisations; ++i) {

		listing = c.getPopulation(i).getListe();
		Population::rouletteWheel(listing, test, parentIndex);
		for (int j = 0; j < nbPop; ++j)
		{
				
			
			for (int z = 0; z <  200; z += 2)
			{
			randomParentIndex1 = 1;
			randomParentIndex2 = 2;
			mParent1 = c.getPopulation(i).getSolution(randomParentIndex1).shape()->encodePropreties();
			mParent2 = c.getPopulation(i).getSolution(randomParentIndex2).shape()->encodePropreties();
			}

			
/*>>>>>>> master*//*		
			randomParentIndex1 = Random::getInstance().uniformRandomize(1, nbPop - 1);
			randomParentIndex2 = Random::getInstance().uniformRandomize(1, nbPop - 1);
			mParent1 = c.getPopulation(0).getrouletteWheel(nbPop).shape()->encodePropreties();
			mParent2 = c.getPopulation(0).rouletteWheel(nbPop).shape()->encodePropreties();
			*/
			//Selection


			//Generate Child
			indexSplit = Random::getInstance().uniformRandomize(1, 30);
			mask = (int)pow(2, indexSplit) - 1;
			//Je realise l'enfant
			mEnfant = mParent1 & mask | mParent2 & ~mask;
			//Mutate
				//Es ce que je fait un mutant ou pas
			if (int a = Random::getInstance().uniformRandomize(1, 100) <= percentageMutate)
			{
				//nombre de bit a changer
				int nbBitChange{ 5 };
				//Position aléatoire
				for (int i = 0; i < nbBitChange; ++i) {
					int indexAléatoire = Random::getInstance().uniformRandomize(1, 30);
					int maskMutate = 1;
					maskMutate <<= (indexAléatoire - 1);
					mEnfant = mEnfant ^ maskMutate;
				}
			}
			delivery(type, j, mWidth, mHeight);
		}
		c.getPopulation(i).parentDeath(mChildSolution,nbPop);
	}
}


void Reproduction::delivery(std::string const & type, size_t i, size_t width, size_t height) {
	Shape2D *shape =nullptr;
	if (type == "cercle") {
		shape = new Cercle();
		shape->decodePropreties(mEnfant);
	}
	if (type == "rectangle") {
		//shape = new Rectangle();
		//shape->decodePropreties(mEnfant);
	}
	if (shape != nullptr) {
		mChildSolution[i].initialize(shape, width, height);
	}
}
