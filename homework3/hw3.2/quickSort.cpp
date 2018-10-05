#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>

int arrayPartition(long *partitionArray, int partLeftBorder, int partRightBorder)
{
	const int pivot = partitionArray[partLeftBorder];
	int position = partLeftBorder + 1;

	for (int i = partLeftBorder + 1; i <= partRightBorder; ++i)
	{
		if (partitionArray[i] < pivot)
		{
			std::swap(partitionArray[i], partitionArray[position]);
			++position;
		}
	}

	std::swap(partitionArray[partLeftBorder], partitionArray[position - 1]);

	return position - 1;
}

int quickSort(long *qsSourceArray, int sortLeftBorder, int sortRightBorder)
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