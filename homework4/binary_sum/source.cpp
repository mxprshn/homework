#include <limits.h>
#include <stdio.h>
#include "binaryOperations.h"

void createBinary(int decimal, short int *binary)
{
	unsigned int bit = 0b10000000000000000000000000000000;
	if (decimal >= 0)
	{
		for (int i = 0; i < bitNumberLength; ++i)
		{
			binary[i] = ((decimal & bit) ? 1 : 0);
			bit = bit >> 1;
		}
	}
	else
	{
		decimal *= -1;
		for (int i = 0; i < bitNumberLength; ++i)
		{
			binary[i] = ((decimal & bit) ? 0 : 1);
			bit = bit >> 1;
		}
	}
}

void printBinary(short int *binary)
{
	for (int i = 0; i < bitNumberLength; ++i)
	{
		printf("%d", binary[i]);
	}

	printf("\n");
}

short int sum(short int *summand1, short int *summand2, short int *result)
{
	for (int i = bitNumberLength - 1; i >= 0; --i)
	{
		result[i] = summand1[i] + summand2[i];
		if ((result[i] > 1) && (i > 0))
		{
			result[i] = 1;
			++result[i - 1];
		}
		else if (result[i] > 1)
		{

		}
	}
	return 0;
}
