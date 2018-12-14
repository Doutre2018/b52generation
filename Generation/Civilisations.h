#include "Populations.h"
#include <vector> 
#include "Console\Console.h"
class Civilisations
{
private:
	Civilisations();
	~Civilisations();
	std::vector<Populations> civilisations_m;

	enum class Color { brightblue , blue, brightcyan, cyan, brightgreen,green,brightmagenta, magenta, brightred,red, brightyellow,yellow};
	static ConsoleColor::Text colors[12];
	Color color = Color::brightblue;
public :
	static Civilisations& getInstance()
	{
		static Civilisations instance;
		return instance;
	}
	
	void createNewPopulations();

	void nextColor();

	Populations getPopulation(int id);
	std::vector<Populations> getAll();
private:

};

