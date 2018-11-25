#include <fstream>
#include <vector>
#include "set.h"

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

	const std::vector<int> ascendingOrderedValues = ascendingOrder(testSet);
	const std::vector<int> descendingOrderedValues = descendingOrder(testSet);

	if (ascendingOrderedValues.size() != descendingOrderedValues.size())
	{
		return false;
	}

	for (unsigned int i = 0; i < ascendingOrderedValues.size() - 1; ++i)
	{
		if (ascendingOrderedValues[i] >= ascendingOrderedValues[i + 1])
		{
			return false;
		}
	}

	for (unsigned int i = 0; i < descendingOrderedValues.size() - 1; ++i)
	{
		if (descendingOrderedValues[i] <= descendingOrderedValues[i + 1])
		{
			return false;
		}
	}

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

	return true;
}