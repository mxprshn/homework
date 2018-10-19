#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "phonebook.h"

int readFile(record *currentBase, const char *fileName)
{
	FILE *baseFile = fopen(fileName, "r");
	int recordNumber = 0;
	
	if (!baseFile)
	{
		return recordNumber;
	}

	while (!feof(baseFile))
	{
		fgets(currentBase[recordNumber].name, nameLength, baseFile);
		fgets(currentBase[recordNumber].number, numberLength, baseFile);
		++recordNumber;
	}

	fclose(baseFile);
	return recordNumber - 1;
}

int writeFile(int writePosition, int recordAmount, record *currentBase)
{
	FILE *baseFile = fopen("base.txt", "a+");

	for (int i = writePosition; i < recordAmount; ++i)
	{
		fprintf(baseFile, "%s", currentBase[i].name);
		fprintf(baseFile, "%s", currentBase[i].number);
	}

	fclose(baseFile);
	return recordAmount;
}

int createRecord(int recordAmount, record *currentBase)
{
	printf("Enter name: ");
	getc(stdin); // to skip the \n symbol after commandCode input
	fgets(currentBase[recordAmount].name, nameLength, stdin);
	printf("Enter number: ");
	fgets(currentBase[recordAmount].number, numberLength, stdin);
	++recordAmount;
	return recordAmount;
}

void printBase(int recordAmount, record *currentBase)
{
	for (int i = 0; i < recordAmount; ++i)
	{
		printf("\n%s", currentBase[i].name);
		printf("%s", currentBase[i].number);
	}
}

int searchName(int recordAmount, record *currentBase)
{
	char targetNumber[numberLength]{};
	printf("Enter the number to find the name: ");
	getc(stdin); // to skip the \n symbol after commandCode input
	fgets(targetNumber, numberLength, stdin);

	for (int i = 0; i < recordAmount; ++i)
	{
		if (strcmp(currentBase[i].number, targetNumber) == 0)
		{
			return i;
		}
	}

	return -1;
}

int searchNumber(int recordAmount, record *currentBase)
{
	char targetName[nameLength]{};
	printf("Enter the name to find the number: ");
	getc(stdin); // to skip the \n symbol after commandCode input
	fgets(targetName, nameLength, stdin);

	for (int i = 0; i < recordAmount; ++i)
	{
		if (strcmp(currentBase[i].name, targetName) == 0)
		{
			return i;
		}
	}

	return -1;
}