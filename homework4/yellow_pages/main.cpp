#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "phonebook.h"

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

	struct Record base[baseSize]{};
	interface(readFile(base, baseFileName), base);
	return 0;
}



