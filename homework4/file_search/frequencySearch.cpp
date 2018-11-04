#include "frequencySearch.h"

int frequencySearch(int *sourceArray, int arrayLength)
{
	int counter = 1;
	int maximum = 0;
	int mostFrequent = sourceArray[0];

	for (int i = 1; i < arrayLength; ++i)
	{
		if (sourceArray[i] == sourceArray[i - 1])
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
			mostFrequent = sourceArray[i - 1];
		}
	}

	return mostFrequent;
}