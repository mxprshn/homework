#include <fstream>
#include <string>
#include <unordered_map>
#include "dictionary.h"

bool programTest()
{
	Dictionary *testDictionary = newDictionary();
	std::unordered_map<std::string, std::string> values;

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




}