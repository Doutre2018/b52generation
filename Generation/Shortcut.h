#ifndef SHORTCUT_H
#define SHORTCUT_H


#include "Generation.h"
class Shortcut
{
private:
	Shortcut();
	~Shortcut();
	void addCivilisations(Civilisations & c);
	void removeCivilisations(Civilisations & c);
	void regenerate(Civilisations & c);
public:
	static Shortcut& getInstance()
	{
		static Shortcut instance;
		return instance;
	}

};

#endif // !SHORTCUT_H
