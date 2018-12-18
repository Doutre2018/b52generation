#include "Generation.h"

#include "Shape2D.h"
#include "Solution.h"
#include "Area.h"
#include "Transactions.h"
#include "Civilisations.h"
#include "Shortcut.h"
#include "Console\ConsoleKeyFilterModifiers.h"
#include "Console\ConsoleKeyFilterUp.h"
#include "Reproduction.h"
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





	loop(State::reproduct);
}

void Generation::loop(State state) {

	while (true)
	{

		Cercle cercle;
		cercle.randomize();
		Solution solution(&cercle);
		solution.fitnessEvaluation();

		processInput();
		testShortcut(state);
		if (Mstep_by_step) {
			state = updateSbS(state);
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
			if (k.modifier(ConsoleKeyEvent::KeyModifier::Alt)) {
				if (toupper(k.keyA()) == '1') {
					Shortcut::getInstance().removeCivilisations();
				}
				else if (toupper(k.keyA()) == '2') {
					Shortcut::getInstance().addCivilisations();
				}
				else if (toupper(k.keyA()) == 'P') {
					Shortcut::getInstance().pause(state);
				}
				else if (toupper(k.keyA()) == 'S') {
					if (Mstep_by_step) {
						Mstep_by_step = false;
					}
					else {
						Mstep_by_step = true;
					}
				}
				
			}
			if (k.modifier(ConsoleKeyEvent::KeyModifier::Shift)) {
				if (toupper(k.keyA()) == 'R') {
					Shortcut::getInstance().regenerate();
				}
				if (toupper(k.keyA()) == 'D') {
					Shortcut::getInstance().reset();
				}
			}

			if (k.modifier(ConsoleKeyEvent::KeyModifier::Ctrl)) {
				if (state == State::idle) {
					if (toupper(k.keyA()) == '1') {
						Area::getInstance().shape_g = "cercle";
					}
					if (toupper(k.keyA()) == '2') {
						Area::getInstance().shape_g = "triangle";
					}
					if (toupper(k.keyA()) == '3') {
						Area::getInstance().shape_g = "rectangle";
					}
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
			//si les conditions sont vrais, arrêter.
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
			Reproduction::getInstance().createChild(Reproduction::getInstance().getState());
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


Generation::State Generation::updateSbS(State & state)
{
	//idle, generation1, fitness, stop,  elitetransfer, reproduct, substitute
	switch (state) {
	case State::idle:
		if (Transactions::getInstance().conditionidle(keyEvents) && Transactions::getInstance().conditionstepbystepKey(keyEvents)) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::generation1:
		if (Transactions::getInstance().conditiongen1() && Transactions::getInstance().conditionstepbystepKey(keyEvents)) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::fitness:
		if (Transactions::getInstance().conditionfitness() && Transactions::getInstance().conditionstepbystepKey(keyEvents)) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::stop:
		if (Transactions::getInstance().conditionstop() && Transactions::getInstance().conditionstepbystepKey(keyEvents)) {
			//si les conditions sont vrais, arrêter.
			return state;
		}
		else {
			//si les conditions sont fausses pour stop, continuer
			return nextState(state);
		}
		break;
	case State::elitetransfer:
		if (Transactions::getInstance().conditionelitetransfer() && Transactions::getInstance().conditionstepbystepKey(keyEvents)) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::reproduct:
		if (Transactions::getInstance().conditionreproduct() && Transactions::getInstance().conditionstepbystepKey(keyEvents)) {
			return nextState(state);
		}
		else {
			return state;
		}
		break;
	case State::substitute:
		if (Transactions::getInstance().conditionsubstitute() && Transactions::getInstance().conditionstepbystepKey(keyEvents)) {
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