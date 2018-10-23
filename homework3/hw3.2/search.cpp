#include "search.h"

void swap(long int *element1, long int *element2)
{
	const long int buffer = *element1;
	*element1 = *element2;
	*element2 = buffer;
}

int binarySearch(long int *sourceArray, int arrayLength, int searchElement)
{
	int leftBorder = 0;
	int rightBorder = arrayLength - 1;

	while (leftBorder <= rightBorder)
	{
		int middle = ((leftBorder + rightBorder) / 2);

		if (sourceArray[middle] == searchElement)
		{
			return middle;
		}

		if (searchElement > sourceArray[middle])
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

int arrayPartition(long int *sourceArray, int leftBorder, int rightBorder)
{
	const long int pivot = sourceArray[leftBorder];
	int position = leftBorder + 1;

	for (int i = leftBorder + 1; i <= rightBorder; ++i)
	{
		if (sourceArray[i] < pivot)
		{
			swap(&sourceArray[i], &sourceArray[position]);
			++position;
		}
	}

	swap(&sourceArray[leftBorder], &sourceArray[position - 1]);

	return position - 1;
}

void quickSort(long int *sourceArray, int leftBorder, int rightBorder)
{
	if (rightBorder >= leftBorder)
	{
		int divisor = arrayPartition(sourceArray, leftBorder, rightBorder);
		quickSort(sourceArray, leftBorder, divisor - 1);
		quickSort(sourceArray, divisor + 1, rightBorder);
	}
}
