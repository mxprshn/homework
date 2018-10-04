#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int quickSort(int *qsSourceArray, int sortLeftBorder, int sortRightBorder);

int main()
{
	int arrayLength = 0;
	printf("Enter the length of the array: ");
	scanf("%d", &arrayLength);

	int *sourceArray = new int[arrayLength] {0};

	printf("Enter %d elements of the array: ", arrayLength);
	for (int i = 0; i < arrayLength; ++i)
	{
		scanf("%d", &sourceArray[i]);
	}

	quickSort(sourceArray, 0, arrayLength - 1);

	int counter = 0;
	int maximum = 0;
	int mostFrequent = sourceArray[0];

	for (int i = 1; i < arrayLength; ++i)
	{
		if (sourceArray[i] == sourceArray[i - 1])
		{
			++counter;
		}
		else
		{
			if (counter > maximum) 
			{
				mostFrequent = sourceArray[i - 1];
				maximum = counter;
				counter = 0;
			}
		}
	}

	if (counter > maximum)
	{
		mostFrequent = sourceArray[arrayLength - 1];
	}

	printf("%d ", mostFrequent);
	return 0;
}
