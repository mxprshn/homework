#include "postfixEvaluation.h"
#include "tests.h"
#include <iostream>
#include <string>


int main()
{
	if (!programTest())
	{
		std::cout << "Test not completed." << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Test completed." << std::endl;
	}

	std::cout << "Enter an expression in Reverse Polish notaton: ";
	std::string expression{};
	std::getline(std::cin, expression);
	bool result = true;
	int value = postfixEvaluation(expression, result);

	if (result)
	{
		std::cout << "Value of the expression: " << value << std::endl;
	}
	else
	{
		std::cout << "Calculation error :(" << std::endl;
	}

	return 0;
}