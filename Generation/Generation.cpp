#include "Generation.h"

#include "Area.h"
#include "Transactions.h"
#include "Civilisations.h"
#include "Shortcut.h"
#include "Console\ConsoleKeyFilterModifiers.h"
#include "Console\ConsoleKeyFilterUp.h"

Generation::Generation():reader_m{ nullptr }, Mstep_by_step{false}
{
}

Generation::~Generation()
{
}

void Generation::start()
{
	Area::getInstance().generateArea();
	Area::getInstance().generatePoint();
	Area::getInstance().showPoint();


	Generation::getInstance().reader_m = &(Console::getInstance().keyReader());
	//Console::getInstance().keyReader().installFilter(new ConsoleKeyFilterModifiers());
	Console::getInstance().keyReader().installFilter(new ConsoleKeyFilterUp());





	loop(State::idle);
}

void Generation::loop(State state) {

	while (true)
	{

		processInput();
		testShortcut(state);
		if (Mstep_by_step) {
			state = update(state);
		}
		else {
			state = update(state);
		}
		render(state);
	}
}

void Generation::testShortcut(State & state) {
	if (keyEvents.size() > 0) {
		
		for (ConsoleKeyEvent k : keyEvents) {
			if (k.modifier(ConsoleKeyEvent::KeyModifier::LeftAlt)) {
				if (toupper(k.keyA()) == '1') {
					Shortcut::getInstance().removeCivilisations();
				}
				else if (toupper(k.keyA()) == '2') {
					Shortcut::getInstance().addCivilisations();
				}
				else if (toupper(k.keyA()) == 'P') {
					Shortcut::getInstance().pause(state);
				}
			}
		}
	}
}
void Generation::processInput()
{
	reader_m->read(keyEvents);

}

void Generation::render(State state)
{
	Area::getInstance().showPoint();
	Area::getInstance().showCivilisations();
	Console::getInstance().writer().push("area");


}

Generation::State Generation::update(State & state)
{
	//idle, generation1, fitness, stop,  elitetransfer, reproduct, substitute
	switch (state) {
	case State::idle : 
		if(Transactions::getInstance().conditionidle(keyEvents)){
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::generation1:
		if (Transactions::getInstance().conditiongen1()) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::fitness:
		if (Transactions::getInstance().conditionfitness()) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::stop:
		if (Transactions::getInstance().conditionstop()) {
			//si les conditions sont vrais, arr�ter.
			return state;
		}
		else {
			//si les conditions sont fausses pour stop, continuer
			return nextState(state);
		}
		break;
	case State::elitetransfer:
		if (Transactions::getInstance().conditionelitetransfer()) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::reproduct:
		if (Transactions::getInstance().conditionreproduct()) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::substitute:
		if (Transactions::getInstance().conditionsubstitute()) {
			return State::fitness;
		}
		else {
			return state;
		}
		break;
	}
}

Generation::State Generation::nextState(State & state)
{
	return (State) ((int) state + 1);
}

void Generation::pause(State & state) {
	if (pausedState == State::pause) {
		pausedState = state;
		state = State::pause;
	}
	else {
		state = pausedState;
		pausedState = State::pause;
	}
}