#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "sortedList.h"
#include "userInterface.h"
#include "tests.h"

int main()
{
	if (!programTest())
	{
		printf("Test not completed.\n");
		return 1;
	}
	else
	{
		printf("Test completed.\n");
	}

	SortedList *list = createList();
	userInterface(list);
	deleteList(list);
	return 0;
}