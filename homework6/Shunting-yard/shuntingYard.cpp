#include "stack.h"
#include <iostream>
#include <string>

std::string shuntingYard(std::string infixExpression)
{
	Stack *operandStack = createStack();
	std::string output{};

	for (int i = 0; i < infixExpression.length(); ++i)
	{
		const char current = infixExpression[i];

		if ((current - '0' >= 0) && (current - '0' <= 9))
		{
			output += current;
			output += ' ';
		}
		else if ((current == '(') || (current == '*') || (current == '/'))
		{
			push(operandStack, current);
		}
		else if ((current == '+') || (current == '-'))
		{
			bool popResult = true;
			bool headResult = true;

			while ((head(operandStack, headResult) == '*') || (head(operandStack, headResult) == '/'))
			{
				output += pop(operandStack, popResult);
				output += ' ';
			}

			if (!popResult)
			{
				deleteStack(operandStack);
				return "Convertation error.";
			}

			push(operandStack, current);
		}
		else if (current == ')')
		{
			bool popResult = true;
			bool headResult = true;

			while (head(operandStack, headResult) != '(')
			{
				output += pop(operandStack, popResult);
				output += ' ';
			}

			pop(operandStack, popResult);

			if ((!popResult) || (!headResult))
			{
				deleteStack(operandStack);
				return "Convertation error.";
			}

		}
	}

	while (!isEmpty(operandStack))
	{
		bool popResult = true;
		output += pop(operandStack, popResult);
		output += ' ';
	}

	deleteStack(operandStack);
	return output;
}

int main()
{
	std::string infixExpression{};
	std::getline(std::cin, infixExpression);
	std::cout << shuntingYard(infixExpression) << std::endl;
	std::cin.get();
	return 0;
}