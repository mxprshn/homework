#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>


int insertionSort(int *sourceArray, int sourceArrayLen)
{
	for (int i = 1; i < sourceArrayLen; ++i)
	{
		const int key = sourceArray[i];
	
		for (int counter = i; counter >= 0; --counter)
		{
			if (key < sourceArray[counter - 1])
			{
				std::swap(sourceArray[counter - 1], sourceArray[counter]);
			}
		}
	}

	return 0;
}

int main()
{
	int testArray[]{ 2, 7, 1, 0, 45, -6, 10 };
	insertionSort(testArray, 7);
	for (int i = 0; i < 7; ++i)
	{
		printf("%d ", testArray[i]);
	}

	return 0;
}