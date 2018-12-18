#ifndef CIVILISATIONS_H
#define CIVILISATIONS_H

#include "Population.h"
#include <vector> 
#include "Console\Console.h"
class Civilisations
{
private:
	Civilisations(){}
	~Civilisations(){}
	std::vector<Population> civilisations_m;

	enum class Color { brightblue , blue, brightcyan, cyan, brightgreen,green,brightmagenta, magenta, brightred,red, brightyellow,yellow};
	static ConsoleColor::Text colors[12];
	Color color = Color::brightblue;
public :
	static Civilisations& getInstance()
	{
		static Civilisations instance;
		return instance;
	}
	
	size_t nbPopulations();

	void createNewPopulations();

	void removeLastPopulations();

	void nextColor();
	void lastColor();

	void regenerate();

	void reset();


	Population getPopulation(int id);
	std::vector<Population> getAll();
	size_t size();

};

#endif //CIVILISATIONS_H
