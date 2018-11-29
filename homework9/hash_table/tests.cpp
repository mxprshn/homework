#include "hashTable.h"
#include "fileReading.h"
#include <fstream>

bool programTest()
{
	std::ifstream testFile("test.txt", std::ios::in);

	if (!testFile.is_open())
	{
		return false;
	}

	HashTable *testTable = newTable();
	std::vector<std::string> testTextWords = readFile(testFile, testTable);

	testFile.close();

	for (std::string current : testTextWords)
	{
		int amount = 0;
		std::ifstream testFile("test.txt", std::ios::in);

		while (!testFile.eof())
		{
			std::string word;
			testFile >> word;
			if (word == current)
			{
				++amount;
			}
		}

		testFile.close();

		if (amountByWord(testTable, current) != amount)
		{
			return false;
		}
	}

	if ((loadFactor(testTable) > 1) || ((float)maxLength(testTable) < averageLength(testTable)))
	{
		return false;
	}

	deleteTable(testTable);

	return (testTable == nullptr);
}