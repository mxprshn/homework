#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int a = 0, b = 0;
	printf("Enter integer divident and divisor: ");
	scanf("%d%d", &a, &b);

	if (b == 0)
	{
		printf("Divison by 0\n");
	}
	else
	{
		int sign = 1;
		if ((a < 0) ^ (b < 0))
		{
			sign = -1;
		}

		a = abs(a);
		b = abs(b);

		int result = 0;
		while (a >= b)
		{
			a -= b;
			++result;
		}

		printf("Result = %d\n", (sign * result));
	}

	return 0;
}