#ifndef GENERATION_H
#define GENERATION_H
#include "Console\Console.h"

#include "Area.h"
#include "Reproduction.h"
#include "Civilisations.h"

class Generation
{
public:
	Generation(size_t height, size_t width, std::string type, size_t nbPopulations, size_t nbObstacles);
	~Generation();

	void start();

	enum class State { idle, generation1, fitness, stop,  elitetransfer, reproduct, substitute, pause};
	
	void pause(State & state);

private :
	State pausedState = State::pause;
	
	void loop(State state);
	void testShortcut(State & state);
	void processInput();
	void render(State state);
	State update(State& state);
	Generation::State nextState(State& state);

	Generation::State checkIdle(State & state);
	Generation::State checkGen1(State & state);
	Generation::State checkFitness(State & state);
	Generation::State checkStop(State & state);
	Generation::State checkEliteTransfer(State & state);
	Generation::State checkReproduct(State & state);

	Generation::State checkSubstitute(State & state);



	bool mStep_by_step;

	ConsoleKeyReader * reader_m;
	ConsoleKeyReader::KeyEvents keyEvents;
	
	size_t mHeight;
	size_t mWidth;
	std::string mType;
	size_t mNbPopulations;
	size_t mNbObstacles;
	
	Area mArea;
	Reproduction mReproductiveSystem;
	Civilisations mCivilisations;
	
};
#endif //GENERATION_H
