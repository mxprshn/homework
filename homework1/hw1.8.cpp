#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	const int arraySize = 15;
	int numbers[arraySize]{};
	int counter = 0;
	printf("Enter %d integer elements: \n", arraySize);

	for (int i = 0; i <= (arraySize - 1); ++i)
	{
		scanf("%d", &numbers[i]);

		if (numbers[i] == 0)
		{
			++counter;
		}
	}

	printf("Amount of zeros: %d\n", counter);

	return 0;
}
