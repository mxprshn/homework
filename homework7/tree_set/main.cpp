#include "set.h"
#include "tests.h"
#include "userInterface.h"
#include <iostream>

int main()
{
	if (!programTest())
	{
		std::cout << "Test failed.\n";
		return 1;
	}
	else
	{
		std::cout << "Test completed.\n\n";
	}

	Set *set = createSet();
	userInterface(set);
	deleteSet(set);
	return 0;
}