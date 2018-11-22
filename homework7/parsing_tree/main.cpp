#include <iostream>
#include "tree.h"

int main()
{
	std::ifstream inputFile("input.txt", std::ios::in);

	if (!inputFile.is_open())
	{
		std::cout << "Input file not found." << std::endl;
		return 1;
	}

	Tree *parsingTree = createTree(inputFile);
	std::cout << treeEvaluation(parsingTree) << std::endl;
	printTree(parsingTree);
	deleteTree(parsingTree);
	return 0;
}