#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include "binaryOperations.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	printf("¬ведите целые числа дл€ двоичного суммировани€: ");
	int decimal1 = 0;
	int decimal2 = 0;

	scanf("%d%d", &decimal1, &decimal2);

	short int binary1[bitNumberLength]{0};
	short int binary2[bitNumberLength]{0};

	createBinary(decimal1, binary1);
	createBinary(decimal2, binary2);

	printBinary(binary1);
	printBinary(binary2);




	return 0;
}