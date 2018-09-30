#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int x = 0;

	printf("Enter integer x: ");
	scanf("%d", &x);
	int sqx = x * x;
	int result = (sqx + x) * (sqx + 1) + 1;
	printf("Result = %d\n", result);

	return 0;
}