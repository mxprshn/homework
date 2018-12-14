#include <fstream>
#include "textSearch.h"

bool programTest()
{
	std::ofstream testFileOut("test.txt", std::ios::out | std::ios::trunc);

	if (!testFileOut.is_open())
	{
		return false;
	}

	std::string testString;

	for (char i = 'a'; i <= 'z'; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			testFileOut << i;
			testString += i;
		}
	}

	testFileOut.close();

	std::ifstream testFileIn("test.txt", std::ios::in);

	if (!testFileIn.is_open())
	{
		return false;
	}

	for (size_t i = 0; i < testString.length() - 2; ++i)
	{
		if (textSearch(testFileIn, testString.substr(i, 3)) != i)
		{
			return false;
		}
	}

	testFileIn.close();

	return true;
}