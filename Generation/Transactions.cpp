#include "Transactions.h"
#include "Reproduction.h"



Transactions::Transactions()
{
}


Transactions::~Transactions()
{
}

bool Transactions::conditionidle(ConsoleKeyReader::KeyEvents & keyEvents)
{
	if (keyEvents.size() > 0) {
		keyEvents.clear();
		return true;
	}
	return false;
}

bool Transactions::conditiongen1()
{
	return false;
}

bool Transactions::conditionfitness()
{
	return false;
}

bool Transactions::conditionstop()
{
	return false;
}

bool Transactions::conditionelitetransfer()
{
	return false;
}

bool Transactions::conditionreproduct()
{
	return false;
}

bool Transactions::conditionsubstitute()
{
	return false;
}

bool Transactions::conditionselect()
{
	if (Reproduction::getInstance().getParent1() != 0 && Reproduction::getInstance().getParent2() != 0)
	{
		return true;
	}
	else
	{
		return false;

	}
	
}

bool Transactions::conditiongeneratechild()
{
	if (Reproduction::getInstance().getEnfant() != 0)
	{
		return true;
	}
	else
	{
		return false;

	}
}

bool Transactions::conditionmutate()
{
	return false;
}

bool Transactions::conditionstepbystepKey(ConsoleKeyReader::KeyEvents & keyEvents) {
	if (keyEvents.size() > 0) {
		for (ConsoleKeyEvent k : keyEvents) {
			if (toupper(k.keyV()) == VK_UP) {
				return true;
			}
		}
	}
	return false;
}