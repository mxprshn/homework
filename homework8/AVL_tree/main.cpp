#include <iostream>
#include "dictionary.h"
#include "user.h"
#include "tests.h"

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

	Dictionary *dictionary = newDictionary();
	userInterface(dictionary);
	deleteDictionary(dictionary);

	return 0;
}