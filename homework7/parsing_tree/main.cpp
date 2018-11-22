#include <iostream>
#include <fstream>
#include "tree.h"
#include "tests.h"

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

	std::ifstream inputFile("input.txt", std::ios::in);

	if (!inputFile.is_open())
	{
		std::cout << "Input file not found." << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Input file opened." << std::endl;
	}

	Tree *parsingTree = createTree(inputFile);

	std::cout << "Value of the expression: " << treeEvaluation(parsingTree) << std::endl;

	std::cout << "Source tree: ";
	printTree(parsingTree);

	deleteTree(parsingTree);
	inputFile.close();
	return 0;
}