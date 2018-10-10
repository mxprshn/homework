#define _CRT_SECURE_NO_WARNINGS
#include <locale.h>
#include <stdio.h>
#include "binaryOperations.h"

int main()
{
	setlocale(LC_ALL, "Russian");

	printf("������� ����� ����� ��� ��������� ������������: ");
	int decimal1 = 0;
	int decimal2 = 0;

	scanf("%d%d", &decimal1, &decimal2);

	bool binary1[bitNumberLength]{0};
	bool binary2[bitNumberLength]{0};
	bool sum[bitNumberLength]{0};

	createBinary(decimal1, binary1);
	createBinary(decimal2, binary2);

	printf("������ ����� � �������������� ����: ");
	printBinary(binary1);

	printf("������ ����� � �������������� ����: ");
	printBinary(binary2);

	printf("����� ����� � �������������� ����:  ");
	sumBinary(binary1, binary2, sum);

	printBinary(sum);

	printf("����� ����� � ���������� �������:   ");
	printf("%d", createDecimal(sum));


	return 0;
}