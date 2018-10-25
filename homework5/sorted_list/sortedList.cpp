#include <stdio.h>
#include "sortedList.h"

bool isEmpty(SortedList list)
{
	return (list.minimum == nullptr);
}

void insert(SortedList &list, int newValue)
{
	auto newElement = new Node{ newValue, 1, nullptr };

	if (isEmpty(list))
	{
		list.minimum = newElement;
	}
	else
	{
		Node *leftNode = nullptr;
		auto rightNode = list.minimum;

		while ((rightNode != nullptr) && (newElement->value > rightNode->value))
		{
			newElement->position += 1;
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
			newElement->next = rightNode;
			list.minimum = newElement;
		}

		auto changePosition = rightNode;

		while (changePosition != nullptr)
		{
			++changePosition->position;
			changePosition = changePosition->next;
		}
	}	
}

void deleteList(SortedList &list)
{
	while (!isEmpty(list))
	{
		const Node *temp = list.minimum;
		list.minimum = list.minimum->next;
		delete temp;
	}
}

bool deleteNode(SortedList &list, int targetPosition)
{
	Node *leftNode = nullptr;
	auto rightNode = list.minimum;

	while ((rightNode != nullptr) && (rightNode->position != targetPosition))
	{
		leftNode = rightNode;
		rightNode = rightNode->next;
	}

	if (rightNode == nullptr)
	{
		return false;
	}

	auto changePosition = rightNode->next;

	if (leftNode != nullptr)
	{
		leftNode->next = rightNode->next;
	}
	else
	{
		list.minimum = rightNode->next;
	}

	delete rightNode;

	while (changePosition != nullptr)
	{
		--changePosition->position;
		changePosition = changePosition->next;
	}

	return true;
}

void printList(SortedList &list)
{
	if (isEmpty(list))
	{
		printf("The list is empty.\n");
	}

	auto temp = list.minimum;
	while (temp != nullptr)
	{
		printf("%d. %d\n", temp->position, temp->value);
		temp = temp->next;
	}
}
