#include "set.h"
#include <iostream>
#include <vector>

int main()
{
	std::cout << "Enter the numbers: ";
	Set *numberSet = createSet();

	int newNumber = -1;

	while (newNumber != 0)
	{
		std::cin >> newNumber;

		if (newNumber != 0)
		{
			add(numberSet, newNumber);
		}
	}

	std::vector<std::pair<int, int>> numbers = ascendingOrder(numberSet);

	for (std::pair<int, int> current : numbers)
	{
		std::cout << "Number: " << current.first << " Amount: " << current.second << std::endl;
	}

	deleteSet(numberSet);

	return 0;
}