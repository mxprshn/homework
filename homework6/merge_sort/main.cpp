#include "list.h"
#include "tests.h"
#include <iostream>
#include <fstream>

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

	std::ifstream file("input.txt", std::ios::in);

	if (!file.is_open())
	{
		std::cout << "File not found." << std::endl;
		return 1;
	}
	else
	{
		std::cout << "File opened." << std::endl;
	}

	List *myList = createList();

	while (!file.eof())
	{
		std::string name{};
		std::string number{};

		getline(file, name);
		getline(file, number);

		add(myList, name, number);
	}

	file.close();

	std::cout << "Command list:" << std::endl;
	std::cout << "0 - Exit program" << std::endl;
	std::cout << "1 - Print list" << std::endl;
	std::cout << "2 - Sort list by name" << std::endl;
	std::cout << "3 - Sort list by number" << std::endl;

	int command = -1;

	while (command != 0)
	{
		std::cin >> command;

		if (command == 1)
		{
			printList(myList);
		}
		else if (command == 2)
		{
			mergeSort(myList, true);
			std::cout << "List is sorted by name." << std::endl;
		}
		else if (command == 3)
		{
			mergeSort(myList, false);
			std::cout << "List is sorted by number." << std::endl;
		}
	}

	deleteList(myList);
	return 0;
}