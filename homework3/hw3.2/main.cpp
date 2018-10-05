#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int quickSort(long *qsSourceArray, int sortLeftBorder, int sortRightBorder);

int binarySearch(long *sortedArray, int sortedArrayLength, int searchElement)
{
	int leftBorder = 0;
	int rightBorder = sortedArrayLength - 1;

	while (leftBorder <= rightBorder)
	{
		int middle = ((leftBorder + rightBorder) / 2);

		if (sortedArray[middle] == searchElement)
		{
			return middle;
		}

		if (searchElement > sortedArray[middle])
		{
			leftBorder = middle + 1;
		}
		else
		{
			rightBorder = middle - 1;
		}
	}

	return -1;
}

bool programTest()
{
	int testArrayLength = rand() % 5000 + 1;
	long int *testArray = new long int[testArrayLength]{0};

	long int mustBeFound = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);
	long int mustNotBeFound = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);

	for (int i = 0; i < testArrayLength; ++i)
	{
		testArray[i] = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);
		while (testArray[i] == mustNotBeFound)
		{
			testArray[i] = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);
		}
	}

	testArray[(testArrayLength - 1) / 5] = mustBeFound;

	if (binarySearch(testArray, testArrayLength, mustBeFound) != ((testArrayLength - 1) / 5))
	{
		printf("%d", binarySearch(testArray, testArrayLength, mustBeFound));
		delete[] testArray;
		return false;
	}

	if (binarySearch(testArray, testArrayLength, mustNotBeFound) != -1)
	{
		delete[] testArray;
		return false;
	}

	delete[] testArray;
	return true;
}

int main()
{
	srand(time(0));

	if (programTest())
	{
		printf("Test completed.\n");
	}
	else
	{
		printf("Test not completed.\n");
		return 0;
	}

	int n = 0;
	long int k = 0;

	printf("Enter 'n' in range 1 <= n <= 5000 and 'k' in range 1 <= k <= 300000: ");
	scanf("%d%d", &n, &k);

	long int *sourceArray = new long int[n]{0};

	for (int i = 0; i < n; ++i)
	{
		sourceArray[i] = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);
	}

	quickSort(sourceArray, 0, n - 1);

	for (int i = 0; i < k; ++i)
	{
		long int matching = (rand() % 1000 + 1) * (rand() % 1000 + 1) * (rand() % 1000 + 1);

		if (binarySearch(sourceArray, n, matching) != -1)
		{
			printf("%d found.\n", matching);
		}
	}

	printf("All matches found.\n");
	
	delete[] sourceArray;
	return 0;
}