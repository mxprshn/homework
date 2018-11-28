#include "list.h"
#include <string>

void split(List *&list, List *&left, List *&right)
{
	left = createList();
	right = createList();

	Node *temp = tail(list);

	for (int i = listLength(list); i > 0; --i)
	{
		if (i > listLength(list) / 2)
		{
			add(right, name(temp), number(temp));
		}
		else
		{
			add(left, name(temp), number(temp));
		}

		temp = previous(temp);
	}
}

void merge(List *&list, List *&left, List *&right, const bool byName)
{
	Node *tempTarget = head(list);
	Node *tempLeft = head(left);
	Node *tempRight = head(right);

	while ((tempLeft != nullptr) || (tempRight != nullptr))
	{
		if ((tempLeft != nullptr) && (tempRight != nullptr))
		{
			const int result = byName ? name(tempLeft).compare(name(tempRight)) : number(tempLeft).compare(number(tempRight));

			if (result < 0)
			{
				copyRecord(tempLeft, tempTarget);
				tempLeft = next(tempLeft);
			}
			else
			{
				copyRecord(tempRight, tempTarget);
				tempRight = next(tempRight);
			}
		}
		else if (tempRight == nullptr)
		{

			copyRecord(tempLeft, tempTarget);
			tempLeft = next(tempLeft);
		}
		else
		{
			copyRecord(tempRight, tempTarget);
			tempRight = next(tempRight);
		}

		tempTarget = next(tempTarget);
	}
}

void mergeSort(List *list, const bool byName)
{
	if (listLength(list) == 1)
	{
		return;
	}

	List *left = nullptr;
	List *right = nullptr;

	split(list, left, right);

	mergeSort(left, byName);
	mergeSort(right, byName);

	merge(list, left, right, byName);

	deleteList(left);
	deleteList(right);
}

bool checkSort(List *list, const bool byName)
{
	Node *temp = next(head(list));

	while (temp != nullptr)
	{
		const int result = byName ? name(temp).compare(name(previous(temp))) : number(temp).compare(number(previous(temp)));

		if (result < 0)
		{
			return false;
		}

		temp = next(temp);
	}

	return true;
}
