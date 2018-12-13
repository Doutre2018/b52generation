#include "Generation.h"



Generation::Generation()
{
}


Generation::~Generation()
{
}

void Generation::start()
{
}

void Generation::loop(State state) {

	timer.start();
	while (true)
	{
		ConsoleKeyEvent::KeyState::KeyDown;

		processInput();
		state = update(state);
		render(state);
		timer.restart();
		int timertime = timer.elapsed();
		while (timertime <= 65000000) {
			timertime = timer.elapsed();

		}
	}
}
