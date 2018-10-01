#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>


int insertionSort(int *insSourceArray, int insSourceArrayLength)
{
	for (int i = 1; i < insSourceArrayLength; ++i)
	{
		const int key = insSourceArray[i];
		int counter = i;

		while ((counter >= 0) && (key < insSourceArray[counter - 1]))
		{
				std::swap(insSourceArray[counter - 1], insSourceArray[counter]);
				--counter;
		}
	}

	return 0;
}

int arrayPartition(int *unpartedArray, int leftBorder, int rightBorder)
{
	const int pivot = unpartedArray[leftBorder];
	int position = leftBorder + 1;

	for (int i = leftBorder + 1; i < rightBorder; ++i)
	{
		if (unpartedArray[i] < pivot)
		{
			std::swap(unpartedArray[i], unpartedArray[position]);
			++position;
		}
	}

	std::swap(unpartedArray[leftBorder], unpartedArray[position - 1]);
	return 0;
}

int quickSort(int *)

int main()
{
	int testArray[]{ 5, 7, 1, 0, 45, -6, 10 };
	arrayPartition(testArray, 0, 7);
	for (int i = 0; i < 7; ++i)
	{
		printf("%d ", testArray[i]);
	}

	return 0;
}