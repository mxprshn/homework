// ≈сли элементы массива в диапазоне [-100; 100], используетс€ сортировка подсчетом, иначе пузырькова€
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

const int leftLimit = -100;
const int rightLimit = 100;
const int arrayLength = 5;

void bubbleSort(int *arrayBubble)
{
	for (int i = 0; i < arrayLength; ++i)
	{
		for (int j = 0; j < (arrayLength - 1 - i); ++j)
		{
			if (arrayBubble[j] > arrayBubble[j + 1])
			{
				int buffer = arrayBubble[j];
				arrayBubble[j] = arrayBubble[j + 1];
				arrayBubble[j + 1] = buffer;
			}
		}
	}
}

int countSort(int *arrayCount)
{
	const int bufferLength = 201;
	int buffer[bufferLength]{0};

	for (int i = 0; i < arrayLength; ++i)
	{
		if ((arrayCount[i] > rightLimit) || (arrayCount[i] < leftLimit))
		{
			return -1;
		}

		++buffer[arrayCount[i] - leftLimit];
	}

	int counter = 0;

	for (int i = 0; i < bufferLength; ++i)
	{
		while (buffer[i] > 0)
		{
			arrayCount[counter] = (i + leftLimit);
			--buffer[i];
			++counter;
		}
	}

	return counter;
}

bool programTest()
{
	int testArray1[]{-8, 56, 0, -100, 14};
	int testArray2[]{-105, 102, 1, 78, -3};

	countSort(testArray1);

	if ((testArray1[4] != 56) && (testArray1[0] != -100) && (countSort(testArray1) != 5))
	{
		return false;
	}

	if (countSort(testArray2) != -1)
	{
		return false;
	}

	bubbleSort(testArray2);

	if ((testArray2[4] != 102) && (testArray1[0] != -105))
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

	printf("Enter %d array elements for sorting: ", arrayLength);

	int array[arrayLength]{0};

	for (int i = 0; i < arrayLength; ++i)
	{
		scanf("%d", &array[i]);
	}

	if (countSort(array) == -1)
	{
		bubbleSort(array);
	}

	for (int i = 0; i < arrayLength; ++i)
	{
		printf("%d ", array[i]);
	}

	return 0;
}

