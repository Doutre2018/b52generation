#include "Generation.h"
#include "Area.h"


Generation::Generation()
{
}


Generation::~Generation()
{
}

void Generation::start()
{
	Area::getInstance().generatePoint();
	loop(State::idle);
}

void Generation::loop(State state) {

	while (true)
	{
		processInput();
		state = update(state);
		render(state);
	}
}

void Generation::processInput()
{
}

void Generation::render(State state)
{
}

Generation::State Generation::update(State & state)
{
	//idle, generation1, fitness, stop,  elitetransfer, selectparent, generatechild, mutate, substitute
	switch (state) {
	case State::idle : 
		if(true){
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	case State::generation1:
		if (true) {
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	case State::fitness:
		if (true) {
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	case State::stop:
		if (true) {
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	case State::elitetransfer:
		if (true) {
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	case State::reproduct:
		if (true) {
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	case State::substitute:
		if (true) {
			return state;
		}
		else {
			return nextState(state);
		}
		break;
	}
}

Generation::State Generation::nextState(State & state)
{
	state = (State) ((int) state + 1);
}
