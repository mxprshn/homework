#include "main.h"

bool programTest()
{
	std::ifstream input1("test1.txt", std::ios::in);
	List *list1 = createList();
	std::ifstream input2("test2.txt", std::ios::in);
	List *list2 = createList();
	std::ifstream input3("test3.txt", std::ios::in);
	List *list3 = createList();

	if (!fileReading(input1, list1))
	{
		input1.close();
		input2.close();
		input3.close();
		deleteList(list1);
		deleteList(list2);
		deleteList(list3);
		return false;
	}

	if (!fileReading(input2, list2))
	{
		input1.close();
		input2.close();
		input3.close();
		deleteList(list1);
		deleteList(list2);
		deleteList(list3);
		return false;
	}

	if (!fileReading(input3, list3))
	{
		input1.close();
		input2.close();
		input3.close();
		deleteList(list1);
		deleteList(list2);
		deleteList(list3);
		return false;
	}

	input1.close();
	input2.close();
	input3.close();

	if (!isSymmetric(list1) || !isSymmetric(list2))
	{
		deleteList(list1);
		deleteList(list2);
		deleteList(list3);
		return false;
	}

	if (isSymmetric(list3))
	{
		deleteList(list1);
		deleteList(list2);
		deleteList(list3);
		return false;
	}

	deleteList(list1);
	deleteList(list2);
	deleteList(list3);
	return true;
}