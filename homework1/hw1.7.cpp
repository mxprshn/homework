#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

int main()
{
	int limit = 0;

	printf("Enter the limit: ");
	scanf("%d", &limit);

	if (limit >= 2)
	{
		bool isSimple = true;
		for (int i = 2; i <= limit; ++i)
		{
			isSimple = true;
			for (int j = 2; j <= sqrt(i); ++j)
			{
				if (i % j == 0)
				{
					isSimple = false;
					break;
				}
			}

			if (isSimple)
			{
				printf("%d\n", i);
			}
		}
	}

	return 0;
}