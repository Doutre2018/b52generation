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
	enum class State { idle, generation1, fitness, stop,  elitetransfer, selectparent, generatechild, mutate, substitute};

	void start();
	void loop(State state);
	void processInput();
	void render(State state);
	State update(State& state);
	void nextState(State& state);
	
};
#endif //GENERATION_H
