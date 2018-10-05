#include "frequencySearch.h"

void swap(int *element1, int *element2)
{
	const int buffer = *element1;
	*element1 = *element2;
	*element2 = buffer;
}

int arrayPartition(int *partitionArray, int partLeftBorder, int partRightBorder)
{
	const int pivot = partitionArray[partLeftBorder];
	int position = partLeftBorder + 1;

	for (int i = partLeftBorder + 1; i <= partRightBorder; ++i)
	{
		if (partitionArray[i] < pivot)
		{
			swap(&partitionArray[i], &partitionArray[position]);
			++position;
		}
	}

	swap(&partitionArray[partLeftBorder], &partitionArray[position - 1]);

	return position - 1;
}

int quickSort(int *qsSourceArray, int sortLeftBorder, int sortRightBorder)
{
	if (sortRightBorder < sortLeftBorder)
	{
		return 0;
	}

	int divisor = arrayPartition(qsSourceArray, sortLeftBorder, sortRightBorder);
	quickSort(qsSourceArray, sortLeftBorder, divisor - 1);
	quickSort(qsSourceArray, divisor + 1, sortRightBorder);

	return 0;
}

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