#ifndef CIVILISATIONS_H
#define CIVILISATIONS_H

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

	void removeLastPopulations();

	void nextColor();

	void lastColor();

	Populations getPopulation(int id);
	std::vector<Populations> getAll();
	size_t size();
private:

};

#endif //CIVILISATIONS_H
