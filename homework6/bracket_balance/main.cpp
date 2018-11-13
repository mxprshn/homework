#include "bracketBalance.h"
#include "tests.h"
#include <iostream>
#include <string>

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