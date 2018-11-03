#include "postfixEvaluation.h"

bool programTest()
{
	std::string testExpression1 = "4 9 2 - 8 + * 8 6 - 1 4 + * /";
	std::string testExpression2 = "2 6 2 - 4 - * 2 6 - 3 4 + * / 2 /";
	std::string testExpression3 = "0 0 /";
	std::string testExpression4 = "9 6 - 1 7 2 + *";

	const int value1 = (4 * (9 - 2 + 8)) / ((8 - 6) * (1 + 4));
	const int value2 = ((2 * (6 - 2 - 4)) / ((2 - 6) * (3 + 4))) / 2;

	bool testResult = true;

	if ((postfixEvaluation(testExpression1, testResult) != value1) || (!testResult))
	{
		return false;
	}

	if ((postfixEvaluation(testExpression2, testResult) != value2) || (!testResult))
	{
		return false;
	}

	postfixEvaluation(testExpression3, testResult);

	if (testResult)
	{
		return false;
	}

	postfixEvaluation(testExpression4, testResult);

	return !testResult;
}