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

int main()
{
	srand(time(0));

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