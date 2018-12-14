#pragma once
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
	void pause();
	void stepbystep();
};

