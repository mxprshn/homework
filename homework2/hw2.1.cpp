#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


int fibonacciRecursion(int elementNumber)
{
	if (elementNumber <= 0)
	{
		return -1;
	}
	
	if ((elementNumber == 1) || (elementNumber == 2))
	{
		return 1;
	}
	
	return (fibonacciRecursion(elementNumber - 1) + fibonacciRecursion(elementNumber - 2));
}

int fibonacciIterative(int limitNumber)
{
	int first = 1;
	int second = 1;
	int current = 1;

	if (limitNumber <= 0)
	{
		return -1;
	}

	if ((limitNumber == 1) || (limitNumber == 2))
	{
		return current;
	}

	for (int i = 3; i <= limitNumber; ++i)
	{
		current = first + second;
		first = second;
		second = current;
	}

	return current;
}

bool programTest()
{
	bool isWorking = true;

	if ((fibonacciRecursion(10) != 55) && (fibonacciIterative(10) != 55))
	{
		isWorking = false;
		return isWorking;
	}
	
	if ((fibonacciRecursion(-3) != -1) && (fibonacciIterative(0) != -1))
	{
		isWorking = false;
		return isWorking;
	}

	if ((fibonacciRecursion(1) != 1) && (fibonacciIterative(1) != 1))
	{
		isWorking = false;
		return isWorking;
	}

	return isWorking;
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

	int amount = 0;

	printf("Enter the amount of elements: ");
	scanf("%d", &amount);

	if (amount <= 0)
	{
		printf("Negative amount\n");
		return 0;
	}

	printf("\nIterative solution: ");
	
	for (int i = 1; i <= amount; ++i)
	{
		printf("%d ", fibonacciIterative(i));
	}

	 printf("\n\nRecursion solution: ");

	for (int i = 1; i <= amount; ++i)
	{
		printf("%d ", fibonacciRecursion(i));
	}
	
	return 0;
	
}