#include "stack.h"
#include "bracketBalance.h"
#include "tests.h"
#include <iostream>

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

	bool isBalanced = isEmpty(bracketStack);
	deleteStack(bracketStack);
	return isBalanced;
}

int main()
{
	if (!programTest())
	{
		std::cout << "Test not completed.\n";
		return 1;
	}
	else
	{
		std::cout << "Test completed.\n";
	}

	std::cout << "Enter a string to check its bracket balance: ";

	std::string sourceString{};

	std::getline(std::cin, sourceString);

	if (checkBalance(sourceString))
	{
		std::cout << "Brackets are balanced.\n";
	}
	else
	{
		std::cout << "Brackets are not balanced.\n";
	}

	return 0;
}