#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "phonebook.h"


void interface(int recordAmount, record *currentBase)
{
	printf("Phonebook by mxprshn. 2018. All rights reserved.\n\n");
	printf("Command list:\n");
	printf("0 - Exit\n");
	printf("1 - Add a record\n");
	printf("2 - Print all records\n");
	printf("3 - Find a number\n");
	printf("4 - Find a name\n");
	printf("5 - Save current data into file\n");

	int commandCode = -1;
	int writePosition = recordAmount;

	while (commandCode != 0)
	{
		printf("\nEnter the command: ");
		scanf("%d", &commandCode);

		switch (commandCode)
		{

		case 1:
		{
			recordAmount = createRecord(recordAmount, currentBase);
			break;
		}

		case 2:
		{
			printBase(recordAmount, currentBase);
			break;
		}

		case 3:
		{
			const int foundPosition = searchNumber(recordAmount, currentBase);

			if (foundPosition >= 0)
			{
				printf("The number you're looking for is %s", currentBase[foundPosition].number);
			}
			else
			{
				printf("Name not found.\n");
			}

			break;
		}

		case 4:
		{
			const int foundPosition = searchName(recordAmount, currentBase);

			if (foundPosition >= 0)
			{
				printf("The name you're looking for is %s", currentBase[foundPosition].name);
			}
			else
			{
				printf("Number not found.\n");
			}

			break;
		}

		case 5:
		{
			writePosition = writeFile(writePosition, recordAmount, currentBase);
			break;
		}

		case 0:
		{
			printf("Exiting programm...");
			break;
		}

		default:
		{
			break;
		}

		}
	}
}

