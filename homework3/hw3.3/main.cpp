#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int quickSort(int *qsSourceArray, int sortLeftBorder, int sortRightBorder);

int frequencySearch(int *sortedArray, int sortedArrayLength)
{
	int counter = 1;
	int maximum = 0;
	int mostFrequent = sortedArray[0];

	for (int i = 1; i < sortedArrayLength; ++i)
	{
		if (sortedArray[i] == sortedArray[i - 1])
		{
			++counter;
		}
		else
		{
			counter = 1;
		}

		if (counter > maximum)
		{
			maximum = counter;
			mostFrequent = sortedArray[i - 1];
		}
	}

	return mostFrequent;
}

bool programTest()
{
	srand(time(0));
	int testArrayLength = rand() % 30 + 5;
	int *testArray = new int[testArrayLength]{0};
	int mostFrequentTest = rand();

	for (int i = 0; i < testArrayLength; ++i)
	{
		if ((i == 0) || ((i % 2) != 0))
		{
			testArray[i] = mostFrequentTest;
		}
		else
		{
			testArray[i] = rand();
		}
	}
		
	quickSort(testArray, 0, testArrayLength - 1);

	if (frequencySearch(testArray, testArrayLength) != mostFrequentTest)
	{
		delete[] testArray;
		return false;
	}
	else
	{
		delete[] testArray;
		return true;
	}
 
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
