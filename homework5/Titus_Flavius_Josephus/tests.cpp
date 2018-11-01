#include "cyclicList.h"
#include "survivorCount.h"

bool programTest()
{
	const int testAmount1 = 1;
	const int testResult1 = 1;

	const int testAmount2 = 30;
	const int testModulus2 = 5;
	const int testResult2 = 3;

	const int testAmount3 = 2;
	const int testResult3Even = 1;
	const int testResult3Odd = 2;

	for (int i = 1; i <= 100; ++i)
	{
		CyclicList *testList1 = createList();

		if (survivorCount(testList1, testAmount1, i) != testResult1)
		{
			deleteList(testList1);
			return false;
		}

		deleteList(testList1);
	}

	CyclicList *testList2 = createList();

	if (survivorCount(testList2, testAmount2, testModulus2) != testResult2)
	{
		deleteList(testList2);
		return false;
	}

	deleteList(testList2);

	for (int i = 2; i <= 100; i += 2)
	{
		CyclicList *testList3 = createList();

		if (survivorCount(testList3, testAmount3, i) != testResult3Even)
		{
			deleteList(testList3);
			return false;
		}

		deleteList(testList3);
	}

	for (int i = 1; i <= 101; i += 2)
	{
		CyclicList *testList4 = createList();

		if (survivorCount(testList4, testAmount3, i) != testResult3Odd)
		{
			deleteList(testList4);
			return false;
		}

		deleteList(testList4);
	}

	return true;
}