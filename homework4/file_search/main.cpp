// Input file consists of the array size (first number) and the integer array (the rest numbers) 
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <locale.h>
#include "frequencySearch.h"

bool programTest()
{
	const int testArray1Length = 10;
	const int testArray2Length = 10;

	int testArray1[testArray1Length] = {0, 3, -1 , 6, 0, 6, 6, 0, 0, 11};
	int testArray2[testArray2Length] = {-98, 0, 23, -98, 54, 76, 2, 23, 1, 0};

	quickSort(testArray1, 0, testArray1Length - 1);
	quickSort(testArray2, 0, testArray2Length - 1);

	if ((frequencySearch(testArray1, testArray1Length) != 0) || (frequencySearch(testArray2, testArray2Length) != -98))
	{
		return false;
	}

	return true;
}

int main()
{
	setlocale(LC_ALL, "Russian");

	if (programTest())
	{
		printf("Тест пройден.\n");
	}
	else
	{
		printf("Тест не пройден.\n");
		return 0;
	}

	FILE *inputFile = fopen("input.txt", "r");

	if (!inputFile)
	{
		printf("Не удалось найти файл.");
		return 1;
	}
	else
	{
		printf("Файл открыт.\n");
	}

	int arrayLength = 0;

	if (fscanf(inputFile, "%d", &arrayLength) == EOF)
	{
		printf("Пустой файл.");
		fclose(inputFile);
		return 1;
	}
	
	int *sourceArray = new int[arrayLength] {0};

	for (int i = 0; i < arrayLength; ++i)
	{
		if (feof(inputFile))
		{
			printf("Недостаточно элементов.");
			delete[] sourceArray;
			fclose(inputFile);
			return 1;
		}

		fscanf(inputFile, "%d", &sourceArray[i]);
	}
		
	quickSort(sourceArray, 0, arrayLength - 1);

	printf("Наиболее часто встречающйся элемент массива: %d. ", frequencySearch(sourceArray, arrayLength));

	delete[] sourceArray;
	fclose(inputFile);

	return 0;
}
