#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include "Console\Console.h"
#include "Generation.h"
class Transactions
{
private:
	Transactions();
	~Transactions();
public : 
	static Transactions& getInstance(){
		static Transactions instance;
		return instance;
	}

	bool conditionselect();
	bool conditiongeneratechild();
	bool conditionmutate();
};
#endif //TRANSACTIONS_H
