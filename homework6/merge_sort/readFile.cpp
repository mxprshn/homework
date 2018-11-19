#include "list.h"
#include <fstream>
#include <string>

bool readFile(std::ifstream &file, List *list)
{
	if (!file.is_open())
	{
		return false;
	}

	while (!file.eof())
	{
		std::string name;
		std::string number;

		getline(file, name);
		getline(file, number);

		add(list, name, number);
	}

	return true;
}