#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "phonebook.h"

int main()
{
	struct record base[baseSize]{};
	interface(readFile(base, baseFileName), base);
	return 0;
}



