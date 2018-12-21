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
	void loop();
	void processInput();
	void testShortcut();
	bool update();
	void render();

	bool checkIdle();



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
