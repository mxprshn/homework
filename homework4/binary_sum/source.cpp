#include <stdio.h>
#include "binaryOperations.h"

void createBinary(int decimal, bool *binary)
{
	unsigned int bit = 0b1000000000000000000000000000000;
	if (decimal >= 0)
	{
		for (int i = 1; i < bitNumberLength; ++i)
		{
			binary[i] = ((decimal & bit) ? 1 : 0);
			bit = bit >> 1;
		}
	}
	else
	{
		decimal *= -1;
		binary[0] = 1;
		for (int i = 1; i < bitNumberLength; ++i)
		{
			binary[i] = ((decimal & bit) ? 0 : 1);
			bit = bit >> 1;
		}

		bool binaryOne[bitNumberLength]{0};
		binaryOne[bitNumberLength - 1] = 1;

		sumBinary(binary, binaryOne, binary);
	}
}

void printBinary(bool *binary)
{
	for (int i = 0; i < bitNumberLength; ++i)
	{
		printf("%d", binary[i]);
	}

	printf("\n");
}

void sumBinary(bool *summand1, bool *summand2, bool *result)
{
	short int shift = 0;
	for (int i = bitNumberLength - 1; i >= 0; --i)
	{
		switch (summand1[i] + summand2[i] + shift)
		{
			case 3:
			{
				shift = 1;
				result[i] = 1;
				break;
			}

			case 2:
			{
				shift = 1;
				result[i] = 0;
				break;
			}

			case 1:
			{
				shift = 0;
				result[i] = 1;
				break;
			}

			default:
			{
				shift = 0;
				result[i] = 0;
				break;
			}
		}				
	}
}

int createDecimal(bool *binary)
{
	int decimal = 0;
	int degreeOfTwo = 1;

	if (binary[0])
	{
		for (int i = 31; i > 1; --i)
		{
			if (!binary[i])
			{
				decimal += degreeOfTwo;
			}

			degreeOfTwo *= 2;
		}

		decimal *= -1;
		decimal -= 1;
	}
	else
	{
		for (int i = 31; i > 1; --i)
		{
			if (binary[i])
			{
				decimal += degreeOfTwo;
			}

			degreeOfTwo *= 2;
		}
	}
	
	return decimal;
}
