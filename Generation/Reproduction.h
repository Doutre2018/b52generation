#ifndef REPRODUCTION_H
#define REPRODUCTION_H
#include <stdint.h>
#include "Solution.h"
#include "Area.h"
#include "Civilisations.h"
class Reproduction
{
private:

	int64_t mParent1;
	int64_t mParent2;
	int64_t mEnfant;
	int percentageMutate;
	size_t mNbChild;
	Solution * mChildSolution;

public:
	Reproduction(size_t nbPop);
	~Reproduction();
	void createChild(Civilisations & c, size_t nbPop, size_t nbCivilisations, std::string type);
	void delivery(std::string type, size_t i);
};

#endif //REPRODUCTION_H

