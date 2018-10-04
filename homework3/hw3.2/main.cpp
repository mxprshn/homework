#define _CRT_SECURE_NO_WARNINGS
#include <algorithm>
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int quickSort(int *qsSourceArray, int sortLeftBorder, int sortRightBorder);

int binarySearch(int *sortedArray, int sortedArrayLength, int searchElement)
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

	unsigned long int *sourceArray = new unsigned long int[n]{0};

	for (int i = 0; i < n; ++i)
	{
		sourceArray[i] = (rand() % 1000) * (rand() % 1000) * (rand() % 1000);
		printf("%d ", sourceArray[i]);
	}
	delete[] sourceArray;
	return 0;
}