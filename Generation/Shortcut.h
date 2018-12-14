#ifndef SHORTCUT_H
#define SHORTCUT_H


#include "Generation.h"
class Shortcut
{
private:
	Shortcut();
	~Shortcut();
public:
	static Shortcut& getInstance()
	{
		static Shortcut instance;
		return instance;
	}

	void addCivilisations();
	void removeCivilisations();
	void pause(Generation::State & state);
	void stepbystep();
};

#endif // !SHORTCUT_H
