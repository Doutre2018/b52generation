#include "Transactions.h"



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
	return false;
}

bool Transactions::conditiongeneratechild()
{
	return false;
}

bool Transactions::conditionmutate()
{
	return false;
}
