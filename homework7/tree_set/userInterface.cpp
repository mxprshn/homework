#include "set.h"
#include <iostream>

void userInterface(Set *set)
{
	std::cout << "Set by mxprshn. All rights reserved. 2018 \n\n";
	std::cout << "Command list:\n";
	std::cout << "0 - Exit program\n";
	std::cout << "1 - Add a new value to the set\n";
	std::cout << "2 - Print elements of the set in ascending order\n";
	std::cout << "3 - Print elements of the set in descending order\n";
	std::cout << "4 - Check existence of value in the set\n";
	std::cout << "5 - Remove value from the set\n";

	int commandCode = -1;

	while (commandCode != 0)
	{
		std::cout << "\nEnter a command: ";
		std::cin >> commandCode;

		switch (commandCode)
		{
		case 1:
		{
			int newValue = 0;
			std::cout << "Enter a value to add: ";
			std::cin >> newValue;

			if (!add(set, newValue))
			{
				std::cout << "This value already exists.\n";
			}

			break;
		}
		case 2:
		{
			if (!ascendingPrint(set))
			{
				std::cout << "The set is empty.";
			}

			std::cout << "\n";
			break;
		}
		case 3:
		{
			if (!descendingPrint(set))
			{
				std::cout << "The set is empty.";
			}

			std::cout << "\n";
			break;
		}
		case 4:
		{
			int targetValue = 0;
			std::cout << "Enter a value to check its existence: ";
			std::cin >> targetValue;

			if (exists(set, targetValue))
			{
				std::cout << "This value exists.\n";
			}
			else
			{
				std::cout << "This value doesn't exist.\n";
			}

			break;
		}
		case 5:
		{
			int targetValue = 0;
			std::cout << "Enter a value to remove: ";
			std::cin >> targetValue;

			if (!remove(set, targetValue))
			{
				std::cout << "This value doesn't exist.\n";
			}

			break;
		}
		default:
		{
			commandCode = 0;
			break;
		}
		}
	}
}