#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "selectionSort.h"

int const sortingArrayLength = 10;

bool programTest()
{
	int const testArray1Length = 10;
	int const testArray2Length = 10;

	int testArray1[testArray1Length] = {-9, 8, 122, -100, 122, 0, 3, 10, -15, -2};
	int testArray2[testArray2Length] = {-10, -5, -1, 0, 0, 5, 15, 31, 100, 101};

	selectionSort(testArray1, testArray1Length);
	selectionSort(testArray2, testArray2Length);

	for (int i = 0; i < testArray1Length - 1; ++i)
	{
		if (testArray1[i + 1] < testArray1[i])
		{
			return false;
		}
	}

	for (int i = 0; i < testArray2Length - 1; ++i)
	{
		if (testArray2[i + 1] < testArray2[i])
		{
			return false;
		}
	}

	return true;
}

int main()
{
	if (programTest())
	{
		printf("Test completed.\n");
	}
	else
	{
		printf("Test not completed.\n");
		return 0;
	}

	int sortingArray[sortingArrayLength]{0};

	printf("Enter %d elements of the array: ", sortingArrayLength);

	for (int i = 0; i < sortingArrayLength; ++i)
	{
		scanf("%d", &sortingArray[i]);
	}

	selectionSort(sortingArray, sortingArrayLength);

	printf("Sorted array: ");

	for (int i = 0; i < sortingArrayLength; ++i)
	{
		printf("%d ", sortingArray[i]);
	}

	return 0;
}