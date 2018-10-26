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
		printf("���� �������.\n");
	}
	else
	{
		printf("���� �� �������.\n");
		return 0;
	}

	FILE *inputFile = fopen("input.txt", "r");

	if (!inputFile)
	{
		printf("�� ������� ����� ����.");
		return 1;
	}
	else
	{
		printf("���� ������.\n");
	}

	int arrayLength = 0;

	if (fscanf(inputFile, "%d", &arrayLength) == EOF)
	{
		printf("������ ����.");
		fclose(inputFile);
		return 1;
	}
	
	int *array = new int[arrayLength] {0};

	if (!scanFile(inputFile, array, arrayLength))
	{
		printf("������������ ���������.");
		fclose(inputFile);
		delete[] array;
		return 1;
	}

	fclose(inputFile);
		
	quickSort(array, 0, arrayLength - 1);

	printf("�������� ����� ������������ ������� �������: %d. ", frequencySearch(array, arrayLength));

	delete[] array;
	return 0;
}
