// Input file consists of the array size (first number) and the integer array (the rest numbers) 
#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include "frequencySearch.h"
#include "test.h"
#include "scanFile.h"

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
	
	int *array = new int[arrayLength] {0};

	if (!scanFile(inputFile, array, arrayLength))
	{
		printf("Недостаточно элементов.");
		fclose(inputFile);
		delete[] array;
		return 1;
	}

	fclose(inputFile);
		
	quickSort(array, 0, arrayLength - 1);

	printf("Наиболее часто встречающйся элемент массива: %d. ", frequencySearch(array, arrayLength));

	delete[] array;
	return 0;
}
