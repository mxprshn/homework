#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>


int insertionSort(int *insSourceArray, int insLeftBorder, int insRightBorder)
{
	for (int i = insLeftBorder; i < insRightBorder; ++i)
	{
		const int key = insSourceArray[i];
		int counter = i;

		while ((counter >= insLeftBorder) && (key < insSourceArray[counter - 1]))
		{
				std::swap(insSourceArray[counter - 1], insSourceArray[counter]);
				--counter;
		}
	}

	return 0;
}

int arrayPartition(int *partitionArray, int partLeftBorder, int partRightBorder)
{
	const int pivot = partitionArray[partLeftBorder];
	int position = partLeftBorder + 1;

	for (int i = partLeftBorder + 1; i < partRightBorder; ++i)
	{
		if (partitionArray[i] < pivot)
		{
			std::swap(partitionArray[i], partitionArray[position]);
			++position;
		}
	}

	std::swap(partitionArray[partLeftBorder], partitionArray[position - 1]);
	return partitionArray[position - 1];
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
	quickSort(qsSourceArray, divisor, sortRightBorder);

	return 0;
} 

int main()
{
	int arrayLength = 0;
	printf("Enter the length of the array: ");
	scanf("%d", &arrayLength);

	int *sourceArray = new int[arrayLength];

	printf("Enter %d elements of the array: ", arrayLength);

	for (int i = 0; i < arrayLength; ++i)
	{
		scanf("%d", &sourceArray[i]);
	}

	quickSort(sourceArray, 0, arrayLength);

	for (int i = 0; i < arrayLength; ++i)
	{
		printf("%d ", sourceArray[i]);
	}

	delete[] sourceArray;
	return 0;
}