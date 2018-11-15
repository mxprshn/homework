#include "stack.h"
#include <string>

std::string shuntingYard(const std::string &infixExpression)
{
	Stack *operandStack = createStack();
	std::string output{};

	for (const char current : infixExpression)
	{
		if ((current - '0' >= 0) && (current - '0' <= 9))
		{
			output += current;
			output += ' ';
		}
		else if (current == '(')
		{
			push(operandStack, current);
		}
		else if ((current == '*') || (current == '/'))
		{
			bool popResult = true;
			bool headResult = true;

			int headValue = head(operandStack, headResult);

			while ((headValue == '*') || (headValue == '/'))
			{
				output += pop(operandStack, popResult);
				output += ' ';
				headValue = head(operandStack, headResult);
			}

			push(operandStack, current);
		}
		else if ((current == '+') || (current == '-'))
		{
			bool popResult = true;
			bool headResult = true;

			int headValue = head(operandStack, headResult);

			while ((headValue == '*') || (headValue == '/') || (headValue == '+') || (headValue == '-'))
			{
				output += pop(operandStack, popResult);
				output += ' ';
				headValue = head(operandStack, headResult);
			}

			push(operandStack, current);
		}
		else if (current == ')')
		{
			bool popResult = true;
			bool headResult = true;

			while ((head(operandStack, headResult) != '(') && (headResult))
			{
				output += pop(operandStack, popResult);				
				output += ' ';
			}

			pop(operandStack, popResult);			
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