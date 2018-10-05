#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "frequencySearch.h"

bool programTest()
{
	const int testArray1Length = 10;
	const int testArray2Length = 10;

	int testArray1[testArray1Length] = {0, 3, -1 , 6, 0, 6, 6, 0, 0, 11};
	int testArray2[testArray2Length] = {-98, 0, 23, -98, 54, 76, 2, 23, 1, 0};

	if ((frequencySearch(testArray1, testArray1Length) != 0) || (frequencySearch(testArray2, testArray2Length) != -98))
	{
		return false;
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

	printf("The most frequent element of array is %d. ", frequencySearch(sourceArray, arrayLength));

	delete[] sourceArray;
	return 0;
}
