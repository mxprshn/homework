#include "stack.h"
#include "postfixEvaluation.h"
#include <string>

bool addition(Stack *operationStack)
{
	bool result = true;
	const int operand1 = pop(operationStack, result);
	const int operand2 = pop(operationStack, result);
	push(operationStack, operand1 + operand2);

	return result;
}

bool diminution(Stack *operationStack)
{
	bool result = true;
	const int operand1 = pop(operationStack, result);
	const int operand2 = pop(operationStack, result);
	push(operationStack, operand2 - operand1);

	return result;
}

bool multiplication(Stack *operationStack)
{
	bool result = true;
	const int operand1 = pop(operationStack, result);
	const int operand2 = pop(operationStack, result);
	push(operationStack, operand1 * operand2);

	return result;
}

bool division(Stack *operationStack)
{
	bool result = true;
	const int operand1 = pop(operationStack, result);
	const int operand2 = pop(operationStack, result);

	if (operand1 == 0)
	{
		return false;
	}

	push(operationStack, operand2 / operand1);

	return result;
}

int postfixEvaluation(const std::string &expression, bool &result)
{
	auto operationStack = createStack();

	for (const char current : expression)
	{
		if ((current - '0' >= 0) && (current - '0' <= 9))
		{
			push(operationStack, current - '0');
		}
		else if ((current == '+') && (!addition(operationStack)))
		{
			result = false;
			return -1;
		}
		else if ((current == '-') && (!diminution(operationStack)))
		{
			result = false;
			return -1;
		}
		else if ((current == '*') && (!multiplication(operationStack)))
		{
			result = false;
			return -1;
		}
		else if ((current == '/') && (!division(operationStack)))
		{
			result = false;
			return -1;
		}
	}

	const int value = pop(operationStack, result);

	if (!isEmpty(operationStack))
	{
		result = false;
	}

	deleteStack(operationStack);
	return value;
}
