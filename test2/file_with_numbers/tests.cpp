#include "main.h"

bool programTest()
{
	const int left = 3;
	const int right = 7;
	std::ifstream testFileF("ftest.txt", std::ios::in);
	std::ofstream testFileG("gtest.txt", std::ios::out | std::ios::trunc);

	if (!numberTransfer(testFileF, testFileG, left, right))
	{
		testFileF.close();
		testFileG.close();
		return false;
	}

	std::ifstream testFileGRead("gtest.txt", std::ios::in);

	bool flagSmaller = true;
	bool flagBigger = false;
	while (!testFileGRead.eof())
	{
		int current = -1;
		testFileGRead >> current;

		if (current == -1)
		{
			continue;
		}

		if ((current >= left) && (flagSmaller = true))
		{
			flagSmaller = false;
		}
		else if (current >= left)
		{
			testFileGRead.close();
			return false;
		}
		
		if ((current > right) && (flagBigger = false))
		{
			flagSmaller = true;
		}
		else if (current > right)
		{
			testFileGRead.close();
			return false;
		}
	}

	testFileGRead.close();
	return true;
}