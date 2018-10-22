#include "creatingDecimal.h"
#include <stdio.h>

const int firstLength = 4;
const int secondLength = 5;

int main()
{
	bool firstNumber[firstLength] = {0, 1, 1, 1};
	bool secondNumber[secondLength] = {0, 0, 1, 1, 0};

	if (createDecimal(firstNumber, firstLength) > createDecimal(secondNumber, secondLength))
	{
		printf("First number is larger.");
	}

	if (createDecimal(firstNumber, firstLength) < createDecimal(secondNumber, secondLength))
	{
		printf("Second number is larger.");
	}

	if (createDecimal(firstNumber, firstLength) == createDecimal(secondNumber, secondLength))
	{
		printf("Numbers are equal.");
	}

	return 0;
}