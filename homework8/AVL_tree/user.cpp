#include <iostream>
#include <string>
#include "dictionary.h"

void userInterface(Dictionary *dictionary)
{
	std::cout << "Command list: " << std::endl;
	std::cout << "0 - Exit" << std::endl;
	std::cout << "1 - Add a new value to dictionary" << std::endl;
	std::cout << "2 - Get a value from dictionary by key" << std::endl;
	std::cout << "3 - Check a key for existence in dictionary" << std::endl;
	std::cout << "4 - Remove a value from dictionary by key" << std::endl;

	std::string command;

	while (command != "0")
	{
		std::cout << std::endl << "Enter a command: ";
		std::getline(std::cin, command);

		if (command == "0")
		{
			break;
		}
		else if (command == "1")
		{
			std::string key;
			std::string value;

			std::cout << "Enter a key: ";
			std::getline(std::cin, key);
			std::cout << "Enter its value: ";
			std::getline(std::cin, value);

			add(dictionary, key, value);
		}
		else if (command == "2")
		{
			std::string key;
			std::cout << "Enter a key: ";
			std::getline(std::cin, key);

			std::cout << "Value of the key: " << value(dictionary, key) << std::endl;
		}
		else if (command == "3")
		{
			std::string key;
			std::cout << "Enter a key: ";
			std::getline(std::cin, key);

			if (exists(dictionary, key))
			{
				std::cout << "This key exists." << std::endl;
			}
			else
			{
				std::cout << "This key doesn't exist." << std::endl;
			}
		}
		else if (command == "4")
		{
			std::string key;
			std::cout << "Enter a key: ";
			std::getline(std::cin, key);

			remove(dictionary, key);
		}
	}
}