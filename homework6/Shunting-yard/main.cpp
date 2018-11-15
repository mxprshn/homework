#include "shuntingYard.h"
#include <iostream>
#include <string>

int main()
{
	std::string infixExpression{};

	std::cout << "Enter an expression in infix notiation: ";
	std::getline(std::cin, infixExpression);
	std::cout << "Expression in postfix notation: " << shuntingYard(infixExpression) << std::endl;

	return 0;
}