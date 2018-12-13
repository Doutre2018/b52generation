#include "Reproduction.h"
#include "Transactions.h"
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
			return state;
		}
		break;
	case StateRep::generatechild:
		if (Transactions::getInstance().conditiongeneratechild()) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case StateRep::mutate:
		if (Transactions::getInstance().conditionmutate()) {
			return StateRep::select;
		}
		else {
			return state;
		}
		break;
	}
}
Reproduction::StateRep Reproduction::nextState(StateRep & state) {
	return (StateRep)((int)state + 1);
}