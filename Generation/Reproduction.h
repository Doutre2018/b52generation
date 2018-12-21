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




	enum class StateRep { select, generatechild, mutate };
	StateRep state;
	StateRep nextState(StateRep & state);
	StateRep & getState();
	int64_t getParent1();
	int64_t getParent2();
	int64_t getEnfant();
	void createChild(StateRep & state, Civilisations c, size_t nbPop, size_t nbCivilisations, std::string type);

	void checkselect(StateRep & state);
	void checkgeneratechild(StateRep & state);
	void checkmutate(StateRep & state, std::string type);

	void delivery(std::string type);

	Solution * getChildren();
	size_t nbChild();
	void setNbChild(size_t nb);
};

#endif //REPRODUCTION_H

