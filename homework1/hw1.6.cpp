#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int main()
{
	char s[] = "aaaaa";
	char s1[] = "aaa";
	int counter = 0;

	if (strlen(s1) > strlen(s))
	{
		printf("Amount of entries: %d\n", counter);
		return 0;
	}
	
	for (int i = 0; i <= (strlen(s) - strlen(s1)); ++i)
	{
		bool flag = true;

		for (int j = 0; j < (strlen(s1) - 1); ++j)
		{
			if (s[i + j] != s1[j])
			{
				flag = false;
				break;
			}
		}

		if (flag)
		{
			++counter;
		}
	}

	printf("Amount of entries: %d\n", counter);

	return 0;
}