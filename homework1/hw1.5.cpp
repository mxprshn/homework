#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	char brackets[] = "()()";
	bool flag = true;
	int counter = 0;


	for (int i = 0; i < (sizeof(brackets) - 1); ++i)
	{
		if ((brackets[i] == ')') && (counter == 0))
		{
			flag = false;
			break;
		}
		else if (brackets[i] == ')')
		{
			--counter;
		}

		if (brackets[i] == '(')
		{
			++counter;
		}
	}

	if (counter > 0)
	{
		flag = false;
	}

	if (flag)
	{
		printf("Brackets are balanced.\n");
	}
	else
	{
		printf("Brackets are not balanced.\n");
	}

	return 0;
}