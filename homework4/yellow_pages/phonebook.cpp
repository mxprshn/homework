#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include "phonebook.h"
#include "record.h"

int readFile(Record *currentBase, const char *fileName)
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

int writeFile(int writePosition, int recordAmount, Record *currentBase)
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

void createRecord(int &recordAmount, Record *currentBase, char *newName, char *newNumber)
{
	strcpy(currentBase[recordAmount].name, newName);
	strcpy(currentBase[recordAmount].number, newNumber);
	++recordAmount;
}

void printBase(int recordAmount, Record *currentBase)
{
	for (int i = 0; i < recordAmount; ++i)
	{
		printf("\n%s", currentBase[i].name);
		printf("%s", currentBase[i].number);
	}
}

int searchName(int recordAmount, Record *currentBase, char *targetNumber)
{	
	for (int i = 0; i < recordAmount; ++i)
	{
		if (strcmp(currentBase[i].number, targetNumber) == 0)
		{
			return i;
		}
	}

	return -1;
}

int searchNumber(int recordAmount, Record *currentBase, char *targetName)
{	
	for (int i = 0; i < recordAmount; ++i)
	{
		if (strcmp(currentBase[i].name, targetName) == 0)
		{
			return i;
		}
	}

	return -1;
}

Record *createBase()
{
	return new Record[baseSize]{};
}

void deleteBase(Record *currentBase)
{
	delete[] currentBase;
}
