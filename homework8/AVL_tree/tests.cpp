#include <fstream>
#include <string>
#include <map>
#include "dictionary.h"

bool programTest()
{
	Dictionary *testDictionary = newDictionary();
	std::map<std::string, std::string> values;

	if (!isEmpty(testDictionary))
	{
		deleteDictionary(testDictionary);
		return false;
	}

	std::ifstream testFile("test.txt", std::ios::in);
	
	if (!testFile.is_open())
	{
		deleteDictionary(testDictionary);
		return false;
	}

	while (!testFile.eof())
	{
		std::string key;
		std::string value;

		std::getline(testFile, key);
		std::getline(testFile, value);

		add(testDictionary, key, value);
		values.insert({key, value});
	}

	testFile.close();

	for (std::pair<std::string, std::string> current : values)
	{
		if (!exists(testDictionary, current.first))
		{
			deleteDictionary(testDictionary);
			return false;
		}

		if (value(testDictionary, current.first) != current.second)
		{
			deleteDictionary(testDictionary);
			return false;
		}

		remove(testDictionary, current.first);

		if (exists(testDictionary, current.first))
		{
			deleteDictionary(testDictionary);
			return false;
		}
	}

	if (!isEmpty(testDictionary))
	{
		deleteDictionary(testDictionary);
		return false;
	}

	deleteDictionary(testDictionary);
	return true;
}