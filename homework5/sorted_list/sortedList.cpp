#include <stdio.h>
#include "sortedList.h"

struct Node
{
	int value = 0;
	int position = 0;
	Node *next = nullptr;
};

struct SortedList
{
	Node *minimum = nullptr;
	int listLength = 0;
};

bool isEmpty(SortedList *list)
{
	return (list->minimum == nullptr);
}

void insert(SortedList *list, int newValue)
{
	auto newElement = new Node{ newValue, list->listLength + 1, nullptr };

	if (isEmpty(list))
	{
		list->minimum = newElement;
	}
	else
	{
		Node *leftNode = nullptr;
		auto rightNode = list->minimum;

		while ((rightNode != nullptr) && (newElement->value > rightNode->value))
		{
			--newElement->position;
			++rightNode->position;
			leftNode = rightNode;
			rightNode = rightNode->next;
		}

		if (leftNode != nullptr)
		{
			newElement->next = rightNode;
			leftNode->next = newElement;
		}
		else
		{
			newElement->next = list->minimum;
			list->minimum = newElement;
		}		
	}	

	++list->listLength;
}

void deleteList(SortedList *list)
{
	while (!isEmpty(list))
	{
		const Node *temp = list->minimum;
		list->minimum = list->minimum->next;
		delete temp;
	}

	delete list;
}

bool deleteNode(SortedList *list, int targetPosition)
{
	if ((targetPosition > list->listLength) || (targetPosition < 0))
	{
		return false;
	}

	Node *leftNode = nullptr;
	auto rightNode = list->minimum;

	while ((rightNode != nullptr) && ((list->listLength - rightNode->position + 1) != targetPosition))
	{
		--rightNode->position;
		leftNode = rightNode;
		rightNode = rightNode->next;
	}


	if (leftNode != nullptr)
	{
		leftNode->next = rightNode->next;
	}
	else
	{
		list->minimum = rightNode->next;
	}

	delete rightNode;

	--list->listLength;

	return true;
}

void printList(SortedList *list)
{
	if (isEmpty(list))
	{
		printf("The list is empty.\n");
	}

	auto temp = list->minimum;

	while (temp != nullptr)
	{
		printf("%d. %d\n", list->listLength - temp->position + 1, temp->value);
		temp = temp->next;
	}
}

SortedList *createList()
{
	return new SortedList;
}

bool checkSorting(SortedList *list)
{
	auto temp = list->minimum;

	if (temp == nullptr)
	{
		return true;
	}

	while (temp->next != nullptr)
	{
		if (temp->value > temp->next->value)
		{
			return false;
		}

		temp = temp->next;
	}

	return true;
}