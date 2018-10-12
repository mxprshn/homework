#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

const int numbersAmount = 100;

int main()
{
	FILE *source = fopen("source.txt", "r");

	if (!source)
	{
		printf("File not found.");
		return 1;
	}

	int readNumbers[numbersAmount]{0};

	int counter = 0;

	while ((!feof(source)) && (counter < numbersAmount))
	{
		fscanf(source, "%d", &readNumbers[counter]);
		++counter;
	}

	fclose(source);

	source = fopen("source.txt", "w");

	for (int i = counter - 1; i >= 0; --i)
	{
		fprintf(source, "%d", readNumbers[i]);
		if (i != 0)
		{
			fprintf(source, " ");
		}
	}

	fclose(source);

	return 0;
}