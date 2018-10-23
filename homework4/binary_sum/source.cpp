#include <stdio.h>
#include "binaryOperations.h"

void createBinary(int decimal, bool *binary)
{
	unsigned int bit = 0b01000000000000000000000000000000;

	binary[0] = (decimal < 0);

	for (int i = 1; i < bitNumberLength; ++i)
	{
		binary[i] = (decimal & bit);
		bit = bit >> 1;
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
	bool shift = 0;
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

	for (int i = bitNumberLength - 1; i > 1; --i)
	{
		if (binary[i] ^ binary[0])
		{
			decimal += degreeOfTwo;
		}
			degreeOfTwo *= 2;
	}

	if (binary[0])
	{
		decimal *= -1;
		decimal -= 1;
	}
			
	return decimal;
}
