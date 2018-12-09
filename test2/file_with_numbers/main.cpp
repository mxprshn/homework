#include "list.h"
#include "tests.h"
#include <fstream>
#include <iostream>

void fileWriting(std::ofstream &file, List *list)
{
	Node *current = tail(list);

	while (current != nullptr)
	{
		file << value(current) << ' ';
		current = previous(current);
	}
}

bool numberTransfer(std::ifstream &input, std::ofstream &output, const int left, const int right)
{
	if (!input.is_open())
	{
		return false;
	}

	List *smaller = createList();
	List *middle = createList();
	List *bigger = createList();

	while (!input.eof())
	{
		int current = 0;
		input >> current;

		if (current < left)
		{
			add(smaller, current);
		}
		else if (current > right)
		{
			add(bigger, current);
		}
		else
		{
			add(middle, current);
		}
	}

	if (!output.is_open())
	{
		deleteList(smaller);
		deleteList(middle);
		deleteList(bigger);
		return false;
	}

	fileWriting(output, smaller);
	fileWriting(output, middle);
	fileWriting(output, bigger);

	deleteList(smaller);
	deleteList(middle);
	deleteList(bigger);

	return true;
}

int main()
{
	if (!programTest())
	{
		return 1;
	}

	int a = 0;
	int b = 0;
	std::cout << "Enter a: ";
	std::cin >> a;
	std::cout << "Enter b: ";
	std::cin >> b;

	if (a > b)
	{
		std::cout << "a must be smaller than b." << std::endl;
		return 1;
	}

	std::ifstream fileF("f.txt", std::ios::in);
	std::ofstream fileG("g.txt", std::ios::out | std::ios::trunc);
	
	if (!numberTransfer(fileF, fileG, a, b))
	{
		fileF.close();
		fileG.close();
		std::cout << "File not found." << std::endl;
		return 1;
	}

	fileF.close();
	fileG.close();

	return 0;
}