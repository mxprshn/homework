#define _CRT_SECURE_NO_WARNINGS
#include "quickSort.h"
#include <stdio.h>


bool programTest()
{
	int const testArray1Length = 10;
	int const testArray2Length = 10;

	int testArray1[testArray1Length] = {-9, 8, 122, -100, 122, 0, 3, 10, -15, -2};
	int testArray2[testArray2Length] = {-10, -5, -1, 0, 0, 5, 15, 31, 100, 101};

	quickSort(testArray1, 0, testArray1Length - 1);
	quickSort(testArray2, 0, testArray2Length - 1);

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

	int arrayLength = 0;
	printf("Enter the length of the array: ");
	scanf("%d", &arrayLength);

	int *sourceArray = new int[arrayLength]{0};

	printf("Enter %d elements of the array: ", arrayLength);

	for (int i = 0; i < arrayLength; ++i)
	{
		scanf("%d", &sourceArray[i]);
	}
	
	quickSort(sourceArray, 0, arrayLength - 1);

	printf("Sorted array: ");

	for (int i = 0; i < arrayLength; ++i)
	{
		printf("%d ", sourceArray[i]);
	}

	delete[] sourceArray;
	return 0;
}