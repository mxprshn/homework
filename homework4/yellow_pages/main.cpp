#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "phonebook.h"

int main()
{
	record *base = new record[baseSize]{};
	interface(readFile(base), base);
	delete[] base;
	return 0;
}



