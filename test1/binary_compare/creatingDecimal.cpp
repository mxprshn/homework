#include "creatingDecimal.h"

int createDecimal(bool *binary, int length)
{
	int decimal = 0;
	int degreeOfTwo = 1;

	for (int i = (length - 1); i >= 0; --i)
	{
		if (binary[i])
		{
			decimal += degreeOfTwo;
		}

		degreeOfTwo *= 2;
	}

	return decimal;
}
