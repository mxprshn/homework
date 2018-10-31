#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "frequencySearch.h"
#include "quickSort.h"

bool programTest()
{
	const int testArray1Length = 10;
	const int testArray2Length = 10;
	const int mostFrequent1 = 0;
	const int mostFrequent2 = -98;

	int testArray1[testArray1Length] = {0, 3, -1 , 6, 0, 6, 6, 0, 0, 11};
	int testArray2[testArray2Length] = {-98, 0, 23, -98, 54, 76, 2, 23, 1, 0};

	quickSort(testArray1, 0, testArray1Length - 1);
	quickSort(testArray2, 0, testArray2Length - 1);

	return ((frequencySearch(testArray1, testArray1Length) == mostFrequent1) || (frequencySearch(testArray2, testArray2Length) == mostFrequent2));
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

	printf("The most frequent element of array is %d. ", frequencySearch(sourceArray, arrayLength));

	delete[] sourceArray;
	return 0;
}
