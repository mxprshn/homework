#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

const int arrayLength = 7;

void arrayMod(int *sourceArray)
{
	int first = sourceArray[0];
	int position = 0;

	for (int i = 1; i < arrayLength; ++i)
	{
		if (sourceArray[i] < first)
		{
			int buffer = sourceArray[i];
			sourceArray[i] = sourceArray[position];
			sourceArray[position] = buffer;
			++position;
		}
	}
}

bool programTest()
{
	int testArray1[arrayLength]{100, 15, 90, 210, -100, 0, 100};
	int testArray2[arrayLength]{17, 100, 6, 18, 30, 120, 0};

	arrayMod(testArray1);
	arrayMod(testArray2);

	if ((testArray1[0] >= 100) || (testArray1[4] < 100))
	{
		return false;
	}

	if ((testArray1[3] >= 100) || (testArray1[6] < 100))
	{
		return false;
	}

	if ((testArray2[0] != 0) && (testArray2[1] != 0))
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

	srand(time(0) * 5);
	
	int randomArray[arrayLength]{};

	for (int i = 0; i < arrayLength; ++i)
	{
		randomArray[i] = rand();
	}

	printf("First element was: %d\n", randomArray[0]);

	arrayMod(randomArray);

	for (int i = 0; i < arrayLength; ++i)
	{
		printf("%d ", randomArray[i]);
	}

	return 0;	
}




