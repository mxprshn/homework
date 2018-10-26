#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "phonebook.h"
#include "tests.h"
#include "interface.h"

const char baseFileName[] = "base.txt";

int main()
{
	if (programTest())
	{
		printf("Tests completed.\n");
	}
	else
	{
		printf("Tests not completed.\n");
		return 1;
	}

	auto base = createBase();
	userInterface(readFile(base, baseFileName), base);
	deleteBase(base);
	return 0;
}



