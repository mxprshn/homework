#include "hashTable.h"
#include <fstream>
#include <vector>
#include <algorithm>

std::vector<std::string> readFile(std::ifstream &file, HashTable *& hashTable)
{
	std::vector<std::string> wordVector;

	if (!file.is_open())
	{
		return wordVector;
	}

	while (!file.eof())
	{
		std::string word;
		file >> word;
		if (!wordExists(hashTable, word))
		{
			wordVector.push_back(word);
		}
		add(hashTable, word);
	}


	std::sort(wordVector.begin(), wordVector.end());

	return wordVector;
}