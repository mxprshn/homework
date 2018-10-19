#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include "binaryOperations.h"


int main()
{
	setlocale(LC_ALL, "Russian");

	if (programTest())
	{
		printf("Тест пройден.\n");
	}
	else
	{
		printf("Тест не пройден.\n");
		return 1;
	}

	printf("Введите целые числа для двоичного суммирования: ");

	int decimal1 = 0;
	int decimal2 = 0;

	scanf("%d%d", &decimal1, &decimal2);

	bool binary1[bitNumberLength]{0};
	bool binary2[bitNumberLength]{0};
	bool sum[bitNumberLength]{0};

	createBinary(decimal1, binary1);
	createBinary(decimal2, binary2);
	sumBinary(binary1, binary2, sum);

	printf("Первое число в дополнительном коде: ");
	printBinary(binary1);

	printf("Второе число в дополнительном коде: ");
	printBinary(binary2);

	printf("Сумма чисел в дополнительном коде:  ");
	printBinary(sum);

	printf("Сумма чисел в десятичной системе:   ");
	printf("%d", createDecimal(sum));


	return 0;
}