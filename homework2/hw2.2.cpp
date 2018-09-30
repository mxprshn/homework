#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int directPower(int baseDirect, int exponentDirect)
{
	if (exponentDirect < 0)
	{
		return -1;
	}

	if (exponentDirect == 0)
	{
		return 1;
	}

	int result = baseDirect;

	for (int i = 1; i < exponentDirect; ++i)
	{
		result *= baseDirect;
	}

	return result;
}

int logPower(int baseLog, int exponentLog)
{
	if (exponentLog < 0)
	{
		return -1;
	}

	if (exponentLog == 0)
	{
		return 1;
	}

	if (exponentLog == 1)
	{
		return baseLog;
	}

	if (exponentLog % 2 == 0)
	{
		return(logPower(baseLog * baseLog, exponentLog / 2));
	}
	else
	{
		return(logPower(baseLog * baseLog, exponentLog / 2) * baseLog);
	}
}

bool programTest()
{
	if (directPower(5, 7) != logPower(5, 7))
	{
		return false;
	}

	if ((directPower(4, 0) != 1) || (logPower(9, 0) != 1))
	{
		return false;
	}

	if ((directPower(8, -3) != -1) || (logPower(11, -4) != -1))
	{
		return false;
	}

	return true;
}

int main()
{
	if (programTest())
	{
		printf("Test completed.\n");
	}
	else
	{
		printf("Test not completed.\n");
		return 0;
	} 

	int base = 0;
	int exponent = 0;

	printf("Enter base and exponent: ");
	scanf("%d%d", &base, &exponent);

	if (exponent < 0)
	{
		printf("Negative exponent.\n");
		return 0;
	}

	printf("Direct Power: %d\n", directPower(base, exponent));
	printf("Logarithmic Power: %d\n", logPower(base, exponent));

	return 0;
}