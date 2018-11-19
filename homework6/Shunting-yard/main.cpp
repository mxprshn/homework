#include "shuntingYard.h"
#include "tests.h"
#include <iostream>
#include <string>

int main()
{
	if (!programTest())
	{
		std::cout << "Test failed." << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Test completed." << std::endl;
	}

	std::string infixExpression;

	std::cout << "Enter an expression in infix notiation: ";
	std::getline(std::cin, infixExpression);
	std::cout << "Expression in postfix notation: " << shuntingYard(infixExpression) << std::endl;

	return 0;
}