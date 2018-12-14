#ifndef GENERATION_H
#define GENERATION_H
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
	enum class State { idle, generation1, fitness, stop,  elitetransfer, reproduct, substitute};

	void start();
private :
	void loop(State state);
	void processInput();
	void render(State state);
	State update(State& state);
	Generation::State nextState(State& state);

	ConsoleKeyReader * reader_m;
	ConsoleKeyReader::KeyEvents keyEvents;
	
};
#endif //GENERATION_H
