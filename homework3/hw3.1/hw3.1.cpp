#define _CRT_SECURE_NO_WARNINGS
#include "quickSort.h"
#include <stdio.h>

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