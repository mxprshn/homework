#include "bracketBalance.h"
#include "stack.h"

bool programTest()
{
	std::string testString{};

	for (int i = 1; i < 53; ++i)
	{
		if ((i % 4) == 1)
		{
			testString += '(';
		}
		else if (((i + 1) % 4) == 2)
		{
			testString += '{';
		}
		else if (((i + 1) % 4) == 3)
		{
			testString += 'O';
		}
		else if (((i + 1) % 4) == 0)
		{
			testString += '[';
		}
	}

	for (int i = 1; i < 53; ++i)
	{
		if ((i % 4) == 1)
		{
			testString += ']';
		}
		else if (((i + 1) % 4) == 2)
		{
			testString += '}';
		}
		else if (((i + 1) % 4) == 3)
		{
			testString += ')';
		}
		else if (((i + 1) % 4) == 0)
		{
			testString += 'A';
		}
	}

	if (!checkBalance(testString))
	{
		return false;
	}

	testString.clear();

	for (int i = 1; i < 53; ++i)
	{
		if ((i % 4) == 1)
		{
			testString += '(';
		}
		else if (((i + 1) % 4) == 2)
		{
			testString += '{';
		}
		else if (((i + 1) % 4) == 3)
		{
			testString += '}';
		}
		else if (((i + 1) % 4) == 0)
		{
			testString += '[';
		}
	}

	for (int i = 1; i < 53; ++i)
	{
		if ((i % 4) == 1)
		{
			testString += ']';
		}
		else if (((i + 1) % 4) == 2)
		{
			testString += '}';
		}
		else if (((i + 1) % 4) == 3)
		{
			testString += ')';
		}
		else if (((i + 1) % 4) == 0)
		{
			testString += 'A';
		}
	}

	if (checkBalance(testString))
	{
		return false;
	}

	testString.clear();

	for (int i = 1; i < 101; ++i)
	{
		if ((i % 4) == 1)
		{
			testString += 'A';
		}
		else if (((i + 1) % 4) == 2)
		{
			testString += 'B';
		}
		else if (((i + 1) % 4) == 3)
		{
			testString += 'C';
		}
		else if (((i + 1) % 4) == 0)
		{
			testString += 'D';
		}
	}

	if (!checkBalance(testString))
	{
		return false;
	}

	testString.clear();

	return checkBalance(testString);

}