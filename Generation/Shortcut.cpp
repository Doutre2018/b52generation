#include "Shortcut.h"
#include "Civilisations.h"

Shortcut::Shortcut()
{
}


Shortcut::~Shortcut()
{
}

void Shortcut::addCivilisations(Civilisations & c)
{
	c.createNewPopulations();
}

void Shortcut::removeCivilisations(Civilisations & c)
{
	c.removeLastPopulations();
}

void Shortcut::regenerate(Civilisations & c) {
	c.regenerate();
}

void Shortcut::reset(Civilisations & c) {
	c.reset();
}
