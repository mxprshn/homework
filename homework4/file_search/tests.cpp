#define _CRT_SECURE_NO_WARNINGS
#include "frequencySearch.h"

bool programTest()
{
	FILE *inputFile = fopen("test.txt", "r");

	if (!inputFile)
	{
		return false;
	}

	int testArray1Length = 0;
	int testArray2Length = 0;

	if (fscanf(inputFile, "%d", &testArray1Length) == EOF)
	{
		fclose(inputFile);
		return false;
	}

	int *testArray1 = new int[testArray1Length] {0};

	if (!scanFile(inputFile, testArray1, testArray1Length))
	{
		fclose(inputFile);
		delete[] testArray1;
		return false;
	}

	if (fscanf(inputFile, "%d", &testArray2Length) == EOF)
	{
		fclose(inputFile);
		delete[] testArray1;
		return false;
	}

	int *testArray2 = new int[testArray2Length] {0};

	if (!scanFile(inputFile, testArray2, testArray2Length))
	{
		fclose(inputFile);
		delete[] testArray1;
		delete[] testArray2;
		return false;
	}

	fclose(inputFile);

	quickSort(testArray1, 0, testArray1Length - 1);
	quickSort(testArray2, 0, testArray2Length - 1);

	if ((frequencySearch(testArray1, testArray1Length) != 0) || (frequencySearch(testArray2, testArray2Length) != -98))
	{
		delete[] testArray1;
		delete[] testArray2;
		return false;
	}

	delete[] testArray1;
	delete[] testArray2;
	return true;
}