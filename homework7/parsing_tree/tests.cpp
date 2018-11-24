#include "tree.h"

bool programTest()
{
	std::ifstream testFile("tests.txt", std::ios::in);

	if (!testFile.is_open())
	{
		return false;
	}

	Tree *testTree1 = createTree(testFile);
	testFile.get();
	Tree *testTree2 = createTree(testFile);
	testFile.get();
	Tree *testTree3 = createTree(testFile);

	testFile.close();

	if (isEmpty(testTree1) || (isEmpty(testTree2)) || (isEmpty(testTree3)))
	{
		return false;
	}

	const int value1 = treeEvaluation(testTree1);
	const int value2 = treeEvaluation(testTree2);
	const int value3 = treeEvaluation(testTree3);

	deleteTree(testTree1);
	deleteTree(testTree2);
	deleteTree(testTree3);

	return ((value1 == value2) && (value1 == value3));
}