#include "frequencySearch.h"
#include "quickSort.h"

void swap(int *element1, int *element2)
{
	const int buffer = *element1;
	*element1 = *element2;
	*element2 = buffer;
}

int arrayPartition(int *sourceArray, int leftBorder, int rightBorder)
{
	const int pivot = sourceArray[leftBorder];
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

void quickSort(int *sourceArray, int leftBorder, int rightBorder)
{
	if (rightBorder >= leftBorder)
	{
		int divisor = arrayPartition(sourceArray, leftBorder, rightBorder);
		quickSort(sourceArray, leftBorder, divisor - 1);
		quickSort(sourceArray, divisor + 1, rightBorder);
	}
}
