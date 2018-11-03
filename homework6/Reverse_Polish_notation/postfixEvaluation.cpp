#include "stack.h"
#include <iostream>
#include <string>

int postfixEvaluation()
{
	auto operationStack = createStack();


}

bool addOperand(Stack *operationStack, int number)
{
	if (((current - '0') >= 0) && ((current - '0') <= 9))
	{
		push(operationStack, current - '0');
		return true;
	}
	
}

int main()
{
	return 0;
}