
#include "Mathematical.h"
#include <vector>
#include "debugstream.h"
#include "Solution.h"

class Solution;

void Mathematical::sortThing(std::vector<Solution> mSolutions) {

	Solution temp{};
	int arraySize = mSolutions.size();
	std::vector<double> index;

	for (int i = 0; i < arraySize; i++)
	{
		mSolutions.at(i).getFitness() > 9999 ? index.push_back(0) : index.push_back(mSolutions.at(i).getFitness());
		

	}
	index.shrink_to_fit();

	std::sort(index.begin(), index.end());
	for (int i = 0; i < 100; i++)
		debug()<<index.at(i);


	;


	//std::sort(mSolutions.begin(), mSolutions.end(), [](Solution l, Solution r) { return l.getFitness() < r.getFitness(); });
	

	/*
	int i = 0; 
	int j = mSolutions.size() - 1;
	while(i < j)
	{
		
		while (mSolutions.at(i).getFitness() > mSolutions.at(i + 1).getFitness())
		{
			temp = mSolutions.at(i + 1);
			mSolutions.at(i) = mSolutions.at(i + 1);
			mSolutions.at(i + 1) = temp;
			i++;
		}
		i = 0;
		j--;
	}
	;
	*/

	/*
		Mathematical::quickSort(mSolutions, 0, mSolutions.size()-1);


	for (int i = 0, j = mSolutions.size()-1; i < mSolutions.size()-1; ++i, j--)
	{
		temp = mSolutions.at(i);
		mSolutions.at(i) = mSolutions.at(j);
		mSolutions.at(j) = temp;


	}
	*/
}


int Mathematical::partition(std::vector<Solution> mSolutions, int l, int u)
{
	int i{}, j{};
	Solution temp{}, v{};
	v = mSolutions.at(l);
	i = l;
	j = u + 1;

	do
	{
		do
			i++;

		while (mSolutions.at(i).getFitness()  <  v.getFitness()  && i < u);

		do
			j--;
		while (v.getFitness() < mSolutions.at(j).getFitness());


		if (i<j)
		{
			temp = mSolutions.at(i);
			mSolutions.at(i) = mSolutions.at(j);
			mSolutions.at(j) = temp;
		}

	} while (i<j);

	mSolutions.at(l) = mSolutions.at(j);
	mSolutions.at(j) = v;

	return j;
}

void Mathematical::quickSort(std::vector<Solution> mSolutions, int l, int u)
{
	int j;
	if (l<u)
	{
		j = partition(mSolutions, l, u);
		quickSort(mSolutions, l, j - 1);
		quickSort(mSolutions, j + 1, u);
	}
}

//