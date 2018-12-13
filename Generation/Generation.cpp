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
	return State();
}
