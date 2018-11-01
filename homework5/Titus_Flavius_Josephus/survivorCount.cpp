#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "cyclicList.h"
#include "survivorCount.h"
#include "tests.h"

int survivorCount(CyclicList *list, int sicariiAmount, int toKill)
{
	for (int i = 1; i <= sicariiAmount; ++i)
	{
		insert(list, i);
	}

	int counter = 1;

	while (!isOnly(list))
	{
		if (counter % toKill == 0)
		{
			deleteCurrent(list);
		}
		else
		{
			moveCurrent(list);
		}

		++counter;
	}

	return currentValue(list);
}

int main()
{
	if (programTest())
	{
		printf("Test completed.\n");
	}
	else
	{
		printf("Test not completed.\n");
		return 1;
	}

	printf("Titus Flavius Josephus simulator 2018\n");

	CyclicList *list = createList();

	int sicariiAmount = 0;
	int toKill = 0;

	printf("Enter the amount of Sicarii: ");
	scanf("%d", &sicariiAmount);

	printf("Enter the killing modulus: ");
	scanf("%d", &toKill);

	printf("Number %d will survive.\n", survivorCount(list, sicariiAmount, toKill));
	
	deleteList(list);

	return 0;
}

