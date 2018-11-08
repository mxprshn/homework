#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sortedList.h"
#include "userInterface.h"

int userInterface(SortedList *list)
{
	printf("Sorted list by mxprshn. 2018. All rights reserved.\n\n");
	printf("Command list:\n");
	printf("0 - Exit\n");
	printf("1 - Add a new value\n");
	printf("2 - Delete a value\n");
	printf("3 - Print the list\n");

	int commandCode = -1;

	while (commandCode != 0)
	{
		printf("\nEnter the command: ");
		scanf("%d", &commandCode);

		if (commandCode == 1)
		{
			int newValue = 0;
			printf("Enter the value: ");
			scanf("%d", &newValue);
			insert(list, newValue);
		}

		else if (commandCode == 2)
		{
			int targetPosition = 0;
			printf("Enter the position of value to delete: ");
			scanf("%d", &targetPosition);
			if (!deleteNode(list, targetPosition))
			{
				printf("There is no value on this position.\n");
			}
		}

		else if (commandCode == 3)
		{
			printf("\n");
			printList(list);
		}

		else if (commandCode == 0)
		{
			printf("Exiting program...");
			return 0;
		}

		else
		{
			return 1;
		}
	}

	return 0;
}
