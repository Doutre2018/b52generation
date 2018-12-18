#include "Shortcut.h"
#include "Civilisations.h"

Shortcut::Shortcut()
{
}


Shortcut::~Shortcut()
{
}

void Shortcut::addCivilisations()
{
	Civilisations::getInstance().createNewPopulations();
}

void Shortcut::removeCivilisations()
{
	Civilisations::getInstance().removeLastPopulations();
}

void Shortcut::pause(Generation::State & state)
{
	Generation::getInstance().pause(state);
}

void Shortcut::regenerate() {
	Civilisations::getInstance().regenerate();
}

void Shortcut::reset() {
	Civilisations::getInstance().reset();
}
