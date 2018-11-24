#include "list.h"
#include "mergeSort.h"
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

	if (!checkSort(testList, true))
	{
		deleteList(testList);
		return false;
	}

	mergeSort(testList, false);

	if (!checkSort(testList, false))
	{
		deleteList(testList);
		return false;
	}

	deleteList(testList);
	return true;
}