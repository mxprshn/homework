#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

bool scanFile(FILE *inputFile, int *array, int arrayLength)
{
	for (int i = 0; i < arrayLength; ++i)
	{
		if (feof(inputFile))
		{
			return false;
		}

		fscanf(inputFile, "%d", &array[i]);
	}

	return true;
}