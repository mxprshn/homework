#include "list.h"
#include <fstream>

bool programTest()
{
	std::ifstream testFile("test.txt", std::ios::in);

	if (!testFile.is_open())
	{
		return false;
	}

	List *testList = createList();

	while (!testFile.eof())
	{
		std::string name{};
		std::string number{};

		getline(testFile, name);
		getline(testFile, number);

		add(testList, name, number);
	}

	testFile.close();

	mergeSort(testList, true);

	if (!checkSortByName(testList))
	{
		return false;
	}

	mergeSort(testList, false);

	if (!checkSortByNumber(testList))
	{
		return false;
	}

	return true;
}