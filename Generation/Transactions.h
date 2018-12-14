#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H
class Transactions
{
private:
	Transactions();
	~Transactions();
public : 
	static Transactions& getInstance()
	{
		static Transactions instance;
		return instance;
	}

	bool conditionidle();
	bool conditiongen1();
	bool conditionfitness();
	bool conditionstop();
	bool conditionelitetransfer();
	bool conditionreproduct();
	bool conditionsubstitute();

	bool conditionselect();
	bool conditiongeneratechild();
	bool conditionmutate();

};
#endif //TRANSACTIONS_H
