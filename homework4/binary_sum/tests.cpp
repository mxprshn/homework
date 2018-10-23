#include "binaryOperations.h"

bool checkSum(int testDecimal1, int testDecimal2)
{
	bool testBinary1[bitNumberLength] {0};
	bool testBinary2[bitNumberLength] {0};
	bool testSum[bitNumberLength] {0};

	createBinary(testDecimal1, testBinary1);
	createBinary(testDecimal2, testBinary2);

	sumBinary(testBinary1, testBinary2, testSum);
	int testResult = createDecimal(testSum);

	return(testResult == (testDecimal1 + testDecimal2));
}

bool programTest()
{
	for (int i = -10; i <= 100; ++i)
	{
		for (int j = -100; j <= 10; ++j)
		{
			if (!checkSum(i, j))
			{
				return false;
			}
		}
	}

	if (!checkSum(2147483647, -2147483647))
	{
		return false;
	}

	return true;
}