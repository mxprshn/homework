#include "quickSort.h"

bool checkSort(int *array, int arrayLength)
{
	for (int i = 0; i < arrayLength - 1; ++i)
	{
		if (array[i + 1] < array[i])
		{
			return false;
		}
	}

	return true;
}

bool programTest()
{
	int const testArray1Length = 10;
	int const testArray2Length = 10;

	int testArray1[testArray1Length] = { -9, 8, 122, -100, 122, 0, 3, 10, -15, -2 };
	int testArray2[testArray2Length] = { -10, -5, -1, 0, 0, 5, 15, 31, 100, 101 };

	quickSort(testArray1, 0, testArray1Length - 1);
	quickSort(testArray2, 0, testArray2Length - 1);

	return (checkSort(testArray1, testArray1Length) && checkSort(testArray2, testArray2Length));
}