#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <time.h>


void insertionSort(int *insSourceArray, int insLeftBorder, int insRightBorder)
{
	for (int i = insLeftBorder; i <= insRightBorder; ++i)
	{
		const int key = insSourceArray[i];
		int counter = i;

		while ((counter > insLeftBorder) && (key < insSourceArray[counter - 1]))
		{
				std::swap(insSourceArray[counter - 1], insSourceArray[counter]);
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
			std::swap(partitionArray[i], partitionArray[position]);
			++position;
		}
	}

	std::swap(partitionArray[partLeftBorder], partitionArray[position - 1]);
		
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

bool programTest()
{
	srand(time(0));
	const int testArrayLength = rand() % 30 + 10;
	int *testArray1 = new int[testArrayLength]{0};
	int *testArray2 = new int[testArrayLength]{0};

	for (int i = 0; i < testArrayLength; ++i)
	{
		testArray1[i] = rand();
		testArray2[i] = testArray1[i];
	}

	quickSort(testArray1, 0, testArrayLength - 1);
	insertionSort(testArray2, 0, testArrayLength - 1);

	for (int i = 1; i < testArrayLength; ++i)
	{
		if ((testArray1[i] != testArray2[i]) || (testArray1[i] < testArray1[i - 1]))
		{
			delete[] testArray1;
			delete[] testArray2;
			return false;
		}
	}

	delete[] testArray1;
	delete[] testArray2;
	return true;
}

int main()
{
	if (programTest)
	{
		printf("Test completed.\n");
	}
	else
	{
		printf("Test not completed.\n");
		return 0;
	}

	int arrayLength = 0;
	printf("Enter the length of the array: ");
	scanf("%d", &arrayLength);

	int *sourceArray = new int[arrayLength];

	printf("Enter %d elements of the array: ", arrayLength);

	for (int i = 0; i < arrayLength; ++i)
	{
		scanf("%d", &sourceArray[i]);
	}
	
	quickSort(sourceArray, 0, arrayLength - 1);

	for (int i = 0; i < arrayLength; ++i)
	{
		printf("%d ", sourceArray[i]);
	}

	delete[] sourceArray;
	return 0;
}