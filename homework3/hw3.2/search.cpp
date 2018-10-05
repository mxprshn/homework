#include "search.h"

void swap(long int *element1, long int *element2)
{
	const long int buffer = *element1;
	*element1 = *element2;
	*element2 = buffer;
}

int binarySearch(long int *searchingArray, int searchingArrayLength, int searchElement)
{
	int leftBorder = 0;
	int rightBorder = searchingArrayLength - 1;

	while (leftBorder <= rightBorder)
	{
		int middle = ((leftBorder + rightBorder) / 2);

		if (searchingArray[middle] == searchElement)
		{
			return middle;
		}

		if (searchElement > searchingArray[middle])
		{
			leftBorder = middle + 1;
		}
		else
		{
			rightBorder = middle - 1;
		}
	}

	return -1;
}

int arrayPartition(long int *partitionArray, int partLeftBorder, int partRightBorder)
{
	const long int pivot = partitionArray[partLeftBorder];
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

int quickSort(long int *qsSourceArray, int sortLeftBorder, int sortRightBorder)
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
