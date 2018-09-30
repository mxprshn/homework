#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>


int insertionSort(int *sourceArray, int sourceArrayLen)
{
	for (int i = 0; i < sourceArrayLen; ++i)
	{
		int current = sourceArray[i];

		for (int counter = i; sourceArray[i] < sourceArray[counter]; --i)
		{
			std::swap(sourceArray[i], sourceArray[counter]);
			--i;
		}

		return 0;
	}
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