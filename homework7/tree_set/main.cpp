#include "set.h"
#include "tests.h"
#include "userInterface.h"
#include <iostream>

int main()
{
	if (!programTest())
	{
		std::cout << "Test failed." << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Test completed." << std::endl << std::endl;
	}

	Set *set = createSet();
	userInterface(set);
	deleteSet(set);
	return 0;
}