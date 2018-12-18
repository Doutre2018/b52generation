#ifndef REPRODUCTION_H
#define REPRODUCTION_H
class Reproduction
{
private:
	Reproduction();
	~Reproduction();
	
public:
	static Reproduction& getInstance()
	{
		static Reproduction instance;
		return instance;
	}
	enum class StateRep { select, generatechild, mutate };
	StateRep state;
	StateRep createChild(StateRep & state);
	StateRep nextState(StateRep & state);

	StateRep & getState();
};

#endif //REPRODUCTION_H