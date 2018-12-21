#include "Generation.h"

#include "Shape2D.h"
#include "Solution.h"
#include "Area.h"
#include "Civilisations.h"
#include "Console\ConsoleKeyFilterModifiers.h"
#include "Console\ConsoleKeyFilterUp.h"
#include "Reproduction.h"


Generation::Generation(size_t height, size_t width, std::string type, size_t nbPopulations, size_t nbObstacles):
	mArea{ Area(width, height) }, mReproductiveSystem{ Reproduction(nbPopulations) }, mCivilisations{ Civilisations()},reader_m { nullptr}, mStep_by_step{ false }, mHeight{ height }, mWidth{ width }, mType{ type }, mNbPopulations{ nbPopulations }, mNbObstacles{ nbObstacles }
{}
Generation::~Generation(){}

void Generation::start(){
	mArea.generateArea();
	mArea.generatePoint(mNbObstacles);
	mArea.showPoint();
	reader_m = &(Console::getInstance().keyReader());
	Console::getInstance().keyReader().installFilter(new ConsoleKeyFilterUp());
	loop(State::reproduct);
}

void Generation::loop(State state) {
	while (true){
		processInput();
		testShortcut(state);
		state = update(state);
		render(state);
	}
}

void Generation::processInput() {
	reader_m->read(keyEvents);
}
void Generation::testShortcut(State & state) {
	if (keyEvents.size() > 0) {
		for (ConsoleKeyEvent k : keyEvents) {
			if (k.modifier(ConsoleKeyEvent::KeyModifier::Alt)) {
				if (toupper(k.keyA()) == '1') {
					mCivilisations.removeLastPopulations();
				}
				else if (toupper(k.keyA()) == '2') {
					mCivilisations.createNewPopulations(mType, mNbPopulations, mWidth, mHeight, mArea.points());
				} else if (toupper(k.keyA()) == 'P') {
					pause(state);
				} else if (toupper(k.keyA()) == 'S') {
					if (mStep_by_step) {
						mStep_by_step = false;
				} else {
						mStep_by_step = true;
					}
				}
			} else if (k.modifier(ConsoleKeyEvent::KeyModifier::Shift)) {
				if (toupper(k.keyA()) == 'R') {
					mCivilisations.regenerate(mType, mNbPopulations, mWidth, mHeight, mArea.points());
				}
				if (toupper(k.keyA()) == 'D') {
					mCivilisations.reset();
				}
			}else if (k.modifier(ConsoleKeyEvent::KeyModifier::Ctrl)) {
				if (state == State::idle) {
					if (toupper(k.keyA()) == '1') {
						mType = "cercle";
					} else if (toupper(k.keyA()) == '2') {
						mType = "triangle";
					} else if (toupper(k.keyA()) == '3') {
						mType = "rectangle";
					}
				}
			}
		}
	}
}

//Checkers of State
void Generation::checkIdle(State & state) {
	if (keyEvents.size() > 0) {
		keyEvents.clear();
		state = nextState(state);
	}
}
void Generation::checkGen1(State & state) {
	if (false) {
		state = nextState(state);
	}
}
void Generation::checkFitness(State & state) {
	if (true) {
		state = nextState(state);
	}
}
void Generation::checkStop(State & state) {
	if (true) {
		state = nextState(state);
	}
}
void Generation::checkEliteTransfer(State & state) {
	if (true) {
		state = nextState(state);
	}
}
void Generation::checkReproduct(State & state) {
	if (mReproductiveSystem.nbChild() >= mNbPopulations - 1) {
		mReproductiveSystem.setNbChild(0);
		state = nextState(state);
	}
}
void Generation::checkSubstitute(State & state) {
	if (true) {
		mCivilisations.getPopulation(0).parentDeath(mReproductiveSystem.getChildren(),mNbPopulations);
		state = State::fitness;
	}
}
Generation::State Generation::nextState(State & state) {
	return (State)((int)state + 1);
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

//Update State
Generation::State Generation::update(State & state)
{
	switch (state) {
	case State::idle: checkIdle(state);
		break;
	case State::generation1: checkGen1(state);
		break;
	case State::fitness: checkFitness(state);
		break;
	case State::stop:checkStop(state);
		break;
	case State::elitetransfer:checkEliteTransfer(state);
		break;
	case State::reproduct:
		if (mCivilisations.nbPopulations()>0) {
			mReproductiveSystem.createChild(mReproductiveSystem.getState(),mCivilisations, mNbPopulations, mCivilisations.nbPopulations(), mType);
		}
		checkReproduct(state);
		break;
	case State::substitute:
		checkSubstitute(state);
		break;
	}
	return state;
}
//render
void Generation::render(State state){
	mArea.showPoint();
	mArea.showCivilisations(mCivilisations.getAll(),mNbPopulations);
	Console::getInstance().writer().push("area");
}


