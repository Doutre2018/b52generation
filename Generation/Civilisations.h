#ifndef CIVILISATIONS_H
#define CIVILISATIONS_H

#include "Population.h"
#include <vector> 
#include "Console\Console.h"
class Civilisations
{
private:

	std::vector<Population> civilisations_m;

	enum class Color { brightblue , blue, brightcyan, cyan, brightgreen,green,brightmagenta, magenta, brightred,red, brightyellow,yellow};
	static ConsoleColor::Text colors[12];
	Color color = Color::brightblue;
public :
	Civilisations() {}
	~Civilisations() {}

	size_t nbPopulations();

	void createNewPopulations();

	void removeLastPopulations();

	void nextColor();
	void lastColor();
	void regenerate(std::string type, size_t nbShape, size_t width, size_t height);

	void reset();


	Population & getPopulation(int id);
	std::vector<Population> &getAll();
	size_t size();

};

#endif //CIVILISATIONS_H
