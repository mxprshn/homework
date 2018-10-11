#include "frequencySearch.h"

int frequencySearch(int *searchingArray, int searchingArrayLength)
{
	int counter = 1;
	int maximum = 0;
	int mostFrequent = searchingArray[0];

	for (int i = 1; i < searchingArrayLength; ++i)
	{
		if (searchingArray[i] == searchingArray[i - 1])
		{
			++counter;
		}
		else
		{
			counter = 1;
		}

		if (counter > maximum)
		{
			maximum = counter;
			mostFrequent = searchingArray[i - 1];
		}
	}

	return mostFrequent;
}