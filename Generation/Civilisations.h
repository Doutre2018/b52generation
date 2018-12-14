#include "Populations.h"
class Civilisations
{
private:
	Civilisations();
	~Civilisations();
	std::list<Populations> getAll();


public :
	static Civilisations& getInstance()
	{
		static Civilisations instance;
		return instance;
	}
	
	Populations getPopulation(int id);
	void std::list<Populations> getAll();
private:

};

