#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char counters[28]{0};

	for (int i = 0; i <= 9; ++i)
	{
		for (int j = 0; j <= 9; ++j)
		{
			for (int k = 0; k <= 9; ++k)
			{
				++counters[i + j + k];
			}
		}
	}

	int amount = 0;

	for (int i = 0; i <= 27; ++i)
	{
		amount += (counters[i] * counters[i]);
	}

	printf("Amount of tickets: %d\n", amount);

	return 0;
}