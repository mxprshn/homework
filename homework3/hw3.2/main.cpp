#define _CRT_SECURE_NO_WARNINGS
#include "search.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

bool programTest()
{
	const int testArrayLength = 10;
	const long int mustBeFound = 146;
	const long int mustNotBeFound = 275;

	long int testArray[testArrayLength] = {43, -4, 12, 0, 0, 3, 146, 3, -14, 18};

	quickSort(testArray, 0, testArrayLength - 1);

	if (binarySearch(testArray, testArrayLength, mustBeFound) == 1)
	{
		return false;
	}

	if (binarySearch(testArray, testArrayLength, mustNotBeFound) != -1)
	{
		return false;
	}

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