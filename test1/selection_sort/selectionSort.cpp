#include "selectionSort.h"

void selectionSort(int *sourceArray, int sourceArrayLength)
{
	for (int i = 0; i < sourceArrayLength; ++i)
	{
		int minimum = sourceArray[i];
		int minimumNumber = i;
		for (int j = i + 1; j < sourceArrayLength; ++j)
		{
			if (sourceArray[j] < minimum)
			{
				minimum = sourceArray[j];
				minimumNumber = j;
			}
		}

		if (i != minimumNumber)
		{
			swap(&sourceArray[i], &sourceArray[minimumNumber]);
		}
	}
}