#include "Generation.h"

#include "Shape2D.h"
#include "Solution.h"
#include "Area.h"
#include "Civilisations.h"
#include "Console\ConsoleKeyFilterModifiers.h"
#include "Console\ConsoleKeyFilterUp.h"
#include "Reproduction.h"


Generation::Generation(size_t height, size_t width, std::string type, size_t nbPopulations, size_t nbObstacles):
	mArea{ Area(width, height) }, mReproductiveSystem{ Reproduction(nbPopulations, width, height) }, mCivilisations{ Civilisations()},reader_m { nullptr}, mStep_by_step{ false }, mHeight{ height }, mWidth{ width }, mType{ type }, mNbPopulations{ nbPopulations }, mNbObstacles{ nbObstacles }
{}
Generation::~Generation(){}

void Generation::start(){
	mArea.generateArea();
	mArea.generatePoint(mNbObstacles);
	mArea.showPoint();
	reader_m = &(Console::getInstance().keyReader());
	Console::getInstance().keyReader().installFilter(new ConsoleKeyFilterUp());
	while (checkIdle()) {}
	loop();
}

void Generation::loop() {
	bool terminer = false;
	while (!terminer){
		processInput();
		testShortcut();
		terminer = update();
		render();
	}
}


void Generation::processInput() {
	reader_m->read(keyEvents);
}
void Generation::testShortcut() {
	if (keyEvents.size() > 0) {
		for (ConsoleKeyEvent k : keyEvents) {
			if (k.modifier(ConsoleKeyEvent::KeyModifier::Alt)) {
				if (toupper(k.keyA()) == '1') {
					mCivilisations.removeLastPopulations();
				}
				else if (toupper(k.keyA()) == '2') {
					mCivilisations.createNewPopulations(mType, mNbPopulations, mWidth, mHeight, mArea.points());
				} else if (toupper(k.keyA()) == 'P') {
					//pause(state);
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
				//if (state == State::idle) {
				//	if (toupper(k.keyA()) == '1') {
				//		mType = "cercle";
				//	} else if (toupper(k.keyA()) == '2') {
				//		mType = "triangle";
				//	} else if (toupper(k.keyA()) == '3') {
				//		mType = "rectangle";
				//	}
				//}
			}
		}
	}
}

//Checkers of State
bool Generation::checkIdle() {
	if (keyEvents.size() > 0) {
		keyEvents.clear();
		return true;
	}
	return false;
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
bool Generation::update(){
	if (mCivilisations.nbPopulations() > 0) {
		// Calculate Fitness

		// Check if stop
		if (false) {
			return true;
		}
		//elite transfer

		//reproduction
		mReproductiveSystem.createChild(mCivilisations, mNbPopulations, mCivilisations.nbPopulations(), mType);
	}
	
	return false;
}
//render
void Generation::render(){
	mArea.showPoint();
	mArea.showCivilisations(mCivilisations.getAll(),mNbPopulations);
	Console::getInstance().writer().push("area");
}


