#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void arrayReverse(int* array, int leftBorder, int rightBorder)
{
	int buffer = 0;
	for (int i = 0; i <= ((rightBorder - leftBorder)/2); ++i)
	{
		buffer = array[leftBorder + i];
		array[leftBorder + i] = array[rightBorder - i];
		array[rightBorder - i] = buffer;
	}
}

int main()
{
	const int m = 5;
	const int n = 3;

	int partedArray[m + n]{};

	printf("Enter %d integer elements: ", (m+n));

	for (int i = 0; i < (m + n); ++i)
	{
		scanf("%d", &partedArray[i]);
	}

	arrayReverse(partedArray, 0, (m - 1));
	arrayReverse(partedArray, m, (m + n - 1));
	arrayReverse(partedArray, 0, (m + n - 1));

	for (int i = 0; i < (m + n); ++i)
	{
		printf("%d ", partedArray[i]);
	}

	return 0;
}