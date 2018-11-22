#include "postfixEvaluation.h"
#include "shuntingYard.h"
#include <string>

bool programTest()
{
	const std::string testExpression1 = "((3 - 1 + 6 - 5) * (2 - 4 + 0)) / ((7 - 3) + (1 + 0) / (3 - 9))";
	const std::string testExpression2 = "(9 - 3) * (4 + 1 + 0 - 7 + 1) / ((1 + 8) * (3 + 3)) * (4 - 4)";

	const int value1 = ((3 - 1 + 6 - 5) * (2 - 4 + 0)) / ((7 - 3) + (1 + 0) / (3 - 9));
	const int value2 = ((9 - 3) * (4 + 1 + 0 - 7 + 1)) / (((1 + 8) * (3 + 3))) * (4 - 4);

	bool result = true;

	if (postfixEvaluation(shuntingYard(testExpression1), result) != value1)
	{
		return false;
	}

	if (!result)
	{
		return false;
	}

	if (postfixEvaluation(shuntingYard(testExpression2), result) != value2)
	{
		return false;
	}

	return result;
}