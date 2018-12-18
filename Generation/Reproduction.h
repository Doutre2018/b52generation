#ifndef REPRODUCTION_H
#define REPRODUCTION_H
#include <stdint.h>
#include "Solution.h"
#include "Area.h"
class Reproduction
{
private:
	Reproduction();
	~Reproduction();
	int64_t mParent1;
	int64_t mParent2;
	int64_t mEnfant;
	int percentageMutate;
	size_t nbChild;
	Solution mChildSolution[NBPOPULATION];

public:
	static Reproduction& getInstance()
	{
		static Reproduction instance;
		return instance;
	}
	enum class StateRep { select, generatechild, mutate };
	StateRep state;
	StateRep createChild(StateRep & state);
	StateRep nextState(StateRep & state);
	StateRep & getState();
	int64_t getParent1();
	int64_t getParent2();
	void delivery();
	Solution * getChildren();
};

#endif //REPRODUCTION_H