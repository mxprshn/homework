#include "quickSort.h"

void swap(int *element1, int *element2)
{
	const int buffer = *element1;
	*element1 = *element2;
	*element2 = buffer;
}

void insertionSort(int *insSourceArray, int insLeftBorder, int insRightBorder)
{
	for (int i = insLeftBorder; i <= insRightBorder; ++i)
	{
		const int key = insSourceArray[i];
		int counter = i;

		while ((counter > insLeftBorder) && (key < insSourceArray[counter - 1]))
		{
			swap(&insSourceArray[counter - 1], &insSourceArray[counter]);
			--counter;
		}
	}
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
	if ((sortRightBorder - sortLeftBorder + 1) < 10)
	{
		insertionSort(qsSourceArray, sortLeftBorder, sortRightBorder);
		return 0;
	}

	int divisor = arrayPartition(qsSourceArray, sortLeftBorder, sortRightBorder);
	quickSort(qsSourceArray, sortLeftBorder, divisor - 1);
	quickSort(qsSourceArray, divisor + 1, sortRightBorder);

	return 0;
}