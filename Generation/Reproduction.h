#ifndef REPRODUCTION_H
#define REPRODUCTION_H
#include <stdint.h>
#include "Solution.h"
#include "Area.h"
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
	Reproduction();
	~Reproduction();

	enum class StateRep { select, generatechild, mutate };
	StateRep state;
	StateRep createChild(StateRep & state);
	StateRep nextState(StateRep & state);
	StateRep & getState();
	int64_t getParent1();
	int64_t getParent2();
	int64_t getEnfant();
	void delivery();
	Solution * getChildren();
	size_t nbChild();
	void setNbChild(size_t nb);
};

#endif //REPRODUCTION_H