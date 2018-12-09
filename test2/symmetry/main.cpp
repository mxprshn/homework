#include "list.h"
#include "tests.h"
#include <fstream>
#include <iostream>

bool isSymmetric(List *list)
{
	Node *left = head(list);
	Node *right = tail(list);

	for (int i = 0; i < listLength(list); ++i)
	{
		if ((left == nullptr) || (right == nullptr))
		{
			return false;
		}

		if (value(left) != value(right))
		{
			return false;
		}

		left = next(left);
		right = previous(right);
	}

	return true;
}

bool fileReading(std::ifstream &input, List *list)
{
	if (!input.is_open())
	{
		return false;
	}

	while (!input.eof())
	{
		int current = 0;
		input >> current;
		add(list, current);
	}

	return true;
}

int main()
{
	if (!programTest())
	{
		return 1;
	}

	std::ifstream input("input.txt", std::ios::in);
	List *list = createList();

	if (!fileReading(input, list))
	{
		deleteList(list);
		return 1;
	}

	if (isSymmetric(list))
	{
		std::cout << "List is symmetric." << std::endl;
	}
	else
	{
		std::cout << "List is not symmetric." << std::endl;
	}

	deleteList(list);
	return 0;
}