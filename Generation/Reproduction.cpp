#include "Reproduction.h"

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
		if (true) {
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	case StateRep::generatechild:
		if (true) {
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	case StateRep::mutate:
		if (true) {
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	}
}
Reproduction::StateRep Reproduction::nextState(StateRep & state) {
	return (StateRep)((int)state + 1);
}