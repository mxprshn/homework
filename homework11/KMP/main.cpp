#include <fstream>
#include <iostream>
#include <string>
#include "textSearch.h"
#include "tests.h"

int main()
{
	if (!programTest())
	{
		std::cout << "Test failed." << std::endl;
		return 1;
	}

	std::ifstream input("input.txt", std::ios::in);

	if (!input.is_open())
	{
		std::cout << "File not found :(" << std::endl;
		return 1;
	}

	std::string pattern;
	std::cout << "Enter a string for search in the file: ";
	getline(std::cin, pattern);

	int result = textSearch(input, pattern);

	input.close();

	if (result >= 0)
	{
		std::cout << "Position of the first string entry: " << result << std::endl;
	}
	else
	{
		std::cout << "String not found." << std::endl;
	}

	return 0;
}