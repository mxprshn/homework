#include "stack.h"
#include "bracketBalance.h"
#include <string>

bool checkBalance(std::string sourceString)
{
	Stack *bracketStack = createStack();

	for (unsigned int i = 0; i < sourceString.size(); ++i)
	{
		bool popResult;

		if ((sourceString[i] == '(') || (sourceString[i] == '{') || (sourceString[i] == '['))
		{
			push(bracketStack, sourceString[i]);
		}

		if ((sourceString[i] == ')') && (pop(bracketStack, popResult) != '('))
		{
			deleteStack(bracketStack);
			return false;
		}

		if ((sourceString[i] == '}') && (pop(bracketStack, popResult) != '{'))
		{
			deleteStack(bracketStack);
			return false;
		}

		if ((sourceString[i] == ']') && (pop(bracketStack, popResult) != '['))
		{
			deleteStack(bracketStack);
			return false;
		}
	}

	const bool isBalanced = isEmpty(bracketStack);
	deleteStack(bracketStack);
	return isBalanced;
}
