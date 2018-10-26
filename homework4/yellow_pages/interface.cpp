#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "phonebook.h"

struct Record
{
	char name[nameLength];
	char number[numberLength];
};

int userInterface(int recordAmount, Record *currentBase)
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

		if (commandCode == 1)
		{
			char newName[nameLength];
			char newNumber[numberLength];
			printf("Enter name: ");
			getc(stdin); // to skip the \n symbol after commandCode input
			fgets(newName, nameLength, stdin);
			printf("Enter number: ");
			fgets(newNumber, numberLength, stdin);

			recordAmount = createRecord(recordAmount, currentBase, newName, newNumber);
		}

		else if (commandCode == 2)
		{
			printBase(recordAmount, currentBase);
		}

		else if (commandCode == 3)
		{
			char targetName[nameLength]{};
			printf("Enter a name to find the number: ");
			getc(stdin); // to skip the \n symbol after commandCode input
			fgets(targetName, nameLength, stdin);

			const int foundPosition = searchNumber(recordAmount, currentBase, targetName);

			if (foundPosition >= 0)
			{
				printf("The number you're looking for is %s", currentBase[foundPosition].number);
			}
			else
			{
				printf("Name not found.\n");
			}
		}

		else if (commandCode == 4)
		{
			char targetNumber[numberLength]{};
			printf("Enter a number to find the name: ");
			getc(stdin); // to skip the \n symbol after commandCode input
			fgets(targetNumber, numberLength, stdin);

			const int foundPosition = searchName(recordAmount, currentBase, targetNumber);

			if (foundPosition >= 0)
			{
				printf("The name you're looking for is %s", currentBase[foundPosition].name);
			}
			else
			{
				printf("Number not found.\n");
			}
		}

		else if (commandCode == 5)
		{
			writePosition = writeFile(writePosition, recordAmount, currentBase);
		}

		else if (commandCode == 0)
		{
			printf("Exiting program...");
		}

		else
		{
			return 1;
		}
	}

	return 0;
}



