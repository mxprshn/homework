#include "hashTable.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>
#include <algorithm>

int main()
{
	HashTable *wordTable = newTable();

	std::ifstream file("input.txt", std::ios::in);

	if (!file.is_open())
	{
		std::cout << "File not found." << std::endl;
	}

	std::vector<std::string> fileWords;

	while (!file.eof())
	{
		std::string word;
		file >> word;
		if (!wordExists(wordTable, word))
		{
			fileWords.push_back(word);
		}
		add(wordTable, word);
	}

	file.close();

	std::sort(fileWords.begin(), fileWords.end());

	for (std::string current : fileWords)
	{
		std::cout << std::setfill('-') << std::setw(15) << std::left << current;
		std::cout << amountByWord(wordTable, current) << std::endl;
	}

	std::cout << "__________________________________" << std::endl;
	std::cout << std::setfill(' ') << std::setw(30) << "Load factor of hash table : " << std::setprecision(2) << loadFactor(wordTable) << std::endl;
	std::cout << std::setw(30) << "Average length of list: " << std::setprecision(2) << averageLength(wordTable) << std::endl;
	std::cout << std::setw(30) <<  "Maximum length of list: " << maxLength(wordTable) << std::endl;

	deleteTable(wordTable);
	return 0;
}