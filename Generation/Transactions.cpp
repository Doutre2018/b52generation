#include "Transactions.h"
#include "Reproduction.h"



Transactions::Transactions()
{
}

Transactions::~Transactions()
{
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

	return true;
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