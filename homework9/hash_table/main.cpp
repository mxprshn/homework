#include "hashTable.h"
#include "fileReading.h"
#include "tests.h"
#include <fstream>
#include <iostream>
#include <iomanip>
#include <vector>

int main()
{
	if (!programTest())
	{
		std::cout << "Test failed." << std::endl;
		return 0;
	}
	else
	{
		std::cout << "Test completed." << std::endl << std::endl;
	}
	HashTable *wordTable = newTable();

	std::ifstream input("input.txt", std::ios::in);

	if (!input.is_open())
	{
		std::cout << "File not open." << std::endl;
	}

	std::vector<std::string> textWords = readFile(input, wordTable);

	input.close();

	std::cout << std::left << "WORD:    AMOUNT:" << std::endl;

	for (std::string current : textWords)
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