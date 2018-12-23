
#include "Mathematical.h"
#include <vector>
#include "Solution.h"
class Solution;

void Mathematical::sortThing(std::vector<Solution> mSolutions) {

	for (int i = 0; i < mSolutions.size(); ++i)
	{

		Mathematical::quickSort(mSolutions, 0, mSolutions.size());



	}



}

int Mathematical::partition(std::vector<Solution> mSolutions, int l, int u)
{
	int i, j;
	Solution temp, v;
	v = mSolutions.at(l);
	i = l;
	j = u + 1;

	do
	{
		do
			i++;

		while (mSolutions.at(i).getFitness()  <  v.getFitness()  && i <= u);

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