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
	enum class State { idle, running, stop };

	void start();
	void loop(State state);

};
#endif //GENERATION_H
