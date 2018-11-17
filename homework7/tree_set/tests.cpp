#include <fstream>
#include "set.h"
#include "tree.h"

void checkTraversal(Node *current, bool &result)
{
	if (((current->left != nullptr) && (current->left->value >= current->value))
		|| ((current->right != nullptr) && (current->right->value <= current->value)))
	{
		result = false;
	}
	else
	{
		if (current->left != nullptr)
		{
			checkTraversal(current->left, result);
		}
		if (current->right != nullptr)
		{
			checkTraversal(current->right, result);
		}
	}
}

bool programTest()
{
	std::ifstream file("test.txt", std::ios::in);

	if (!file.is_open())
	{
		return false;
	}

	Set *testSet = createSet();

	while (!file.eof())
	{
		int newValue = 0;
		file >> newValue;
		add(testSet, newValue);
	}

	file.close();

	bool isBinarySearch = true;
	checkTraversal(testSet->root, isBinarySearch);

	file.open("test.txt", std::ios::in);

	while (!file.eof())
	{
		int existingValue = 0;
		file >> existingValue;
		if (!exists(testSet, existingValue))
		{
			return false;
		}
	}

	file.close();

	file.open("test.txt", std::ios::in);

	while (!file.eof())
	{
		int existingValue = 0;
		file >> existingValue;
		remove(testSet, existingValue);
	}

	file.close();

	if (!isEmpty(testSet))
	{
		return false;
	}

	deleteSet(testSet);
	return isBinarySearch;
}