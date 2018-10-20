#include "phonebook.h"
#include <string.h>

const int realRecordAmount = 7;

bool programTest()
{
	struct Record testBase[baseSize]{};
	int testRecordAmount = readFile(testBase, testBaseFileName);

	if (testRecordAmount != realRecordAmount)
	{
		return false;
	}

	char testName1[] = {"Bill Gates\n"};
	char testNumber1[] = {"88005553535\n"};

	char testName2[] = {"Bjarne Stroustrup\n"};
	char testNumber2[] = {"89813343001\n"};

	char testName3[] = {"Elon Musk\n"};
	char testNumber3[] = {"89821112000\n"};
	
	testRecordAmount = createRecord(testRecordAmount, testBase, testName1, testNumber1);

	if (testRecordAmount != realRecordAmount + 1)
	{
		return false;
	}

	if ((searchName(testRecordAmount, testBase, testNumber1) != -1) && (searchName(testRecordAmount, testBase, testNumber2) != -1))
	{
		if (strcmp(testBase[searchName(testRecordAmount, testBase, testNumber1)].name, testName1) != 0)
		{
			return false;
		}

		if (strcmp(testBase[searchName(testRecordAmount, testBase, testNumber2)].name, testName2) != 0)
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	if ((searchNumber(testRecordAmount, testBase, testName1) != -1) && (searchNumber(testRecordAmount, testBase, testName2) != -1))
	{
		if (strcmp(testBase[searchNumber(testRecordAmount, testBase, testName1)].number, testNumber1) != 0)
		{
			return false;
		}

		if (strcmp(testBase[searchNumber(testRecordAmount, testBase, testName2)].number, testNumber2) != 0)
		{
			return false;
		}
	}
	else
	{
		return false;
	}

	if (searchName(testRecordAmount, testBase, testNumber3) != -1)
	{
		return false;
	}

	if (searchNumber(testRecordAmount, testBase, testName3) != -1)
	{
		return false;
	}

	return true;
}