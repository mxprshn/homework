#include "sortedList.h"

bool programTest()
{
	SortedList *testList = createList();

	for (int i = 100; i >= -100; --i)
	{
		insert(testList, i);
	}

	if (!checkSorting(testList))
	{
		deleteList(testList);
		return false;
	}

	for (int i = 1; i <= 100; ++i)
	{
		deleteNode(testList, i);

		if (!checkSorting(testList))
		{
			deleteList(testList);
			return false;
		}
	}

	for (int i = 101; i >= 1; --i)
	{
		deleteNode(testList, i);

		if (!checkSorting(testList))
		{
			deleteList(testList);
			return false;
		}
	}

	if (!isEmpty(testList))
	{
		deleteList(testList);
		return false;
	}

	deleteList(testList);
	return true;
}
