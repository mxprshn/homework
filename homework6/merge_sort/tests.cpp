#include "list.h"
#include "readFile.h"
#include <fstream>

bool programTest()
{
	std::ifstream testFile("test.txt", std::ios::in);
	List *testList = createList();

	if (!readFile(testFile, testList))
	{
		deleteList(testList);
		return false;
	}

	testFile.close();

	mergeSort(testList, true);

	if (!checkSortByName(testList))
	{
		deleteList(testList);
		return false;
	}

	mergeSort(testList, false);

	if (!checkSortByNumber(testList))
	{
		deleteList(testList);
		return false;
	}

	deleteList(testList);
	return true;
}