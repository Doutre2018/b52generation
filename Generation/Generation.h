#ifndef GENERATION_H
#define GENERATION_H
#include "Console\Console.h"

class Generation
{
private:
	Generation();
	~Generation();
public:
	static Generation& getInstance()
	{
		static Generation instance;
		return instance;
	}

	void start(size_t height, size_t width, std::string type, size_t nbPopulations, size_t nbObstacles);

	enum class State { idle, generation1, fitness, stop,  elitetransfer, reproduct, substitute, pause};
	
	void pause(State & state);

private :
	State pausedState = State::pause;
	
	void loop(State state);
	void testShortcut(State & state);
	void processInput();
	void render(State state);
	State update(State& state);
	Generation::State updateSbS(State & state);
	Generation::State nextState(State& state);

	bool Mstep_by_step;

	ConsoleKeyReader * reader_m;
	ConsoleKeyReader::KeyEvents keyEvents;
	
	size_t mHeight;
	size_t mWidth;
	std::string mType;
	size_t mNbPopulations;
	size_t mNbObstacles;
	
};
#endif //GENERATION_H
