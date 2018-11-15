#include "list.h"
#include <iostream>

struct Node
{
	std::string name{};
	std::string number{};
	Node *previous = nullptr;
	Node *next = nullptr;
};

struct List
{
	Node *head = nullptr;
	Node *tail = nullptr;
	int length = 0;
};

List *createList()
{
	return new List;
}

bool isEmpty(List *list)
{
	return (list->length == 0);
}

void add(List *list, const std::string &name, const std::string &number)
{
	list->head = new Node{ name, number, nullptr, list->head };

	if (isEmpty(list))
	{
		list->tail = list->head;
	}
	else
	{
		list->head->next->previous = list->head;
	}

	++list->length;
}

void deleteList(List *&list)
{
	while ((list->head) != (list->tail))
	{
		const Node *temp = list->head;
		list->head = list->head->next;
		delete temp;
	}

	delete (list->head);
	delete list;
	list = nullptr;
}

void split(List *list, List *left, List *right)
{	
	Node *temp = list->tail;

	for (int i = (list->length); i > 0; --i)
	{
		if (i > (list->length) / 2)
		{
			add(right, temp->name, temp->number);
		}
		else
		{
			add(left, temp->name, temp->number);
		}

		temp = temp->previous;
	}
}

void mergeByName(List *list, List *left, List *right)
{
	Node *tempTarget = list->head;
	Node *tempLeft = left->head;
	Node *tempRight = right->head;

	while ((tempLeft != nullptr) || (tempRight != nullptr))
	{
		if ((tempRight == nullptr) || ((tempLeft != nullptr) && (tempLeft->name.compare(tempRight->name) < 0)))
		{
			tempTarget->name = tempLeft->name;
			tempTarget->number = tempLeft->number;
			tempLeft = tempLeft->next;
		}
		else
		{
			tempTarget->name = tempRight->name;
			tempTarget->number = tempRight->number;
			tempRight = tempRight->next;
		}

		tempTarget = tempTarget->next;
	}
}

void mergeByNumber(List *list, List *left, List *right)
{
	Node *tempTarget = list->head;
	Node *tempLeft = left->head;
	Node *tempRight = right->head;

	while ((tempLeft != nullptr) || (tempRight != nullptr))
	{
		if ((tempRight == nullptr) || ((tempLeft != nullptr) && (tempLeft->number.compare(tempRight->number) < 0)))
		{
			tempTarget->name = tempLeft->name;
			tempTarget->number = tempLeft->number;
			tempLeft = tempLeft->next;
		}
		else
		{
			tempTarget->name = tempRight->name;
			tempTarget->number = tempRight->number;
			tempRight = tempRight->next;
		}

		tempTarget = tempTarget->next;
	}
}

void mergeSort(List *list, bool byName)
{
	if (list->length == 1)
	{
		return;
	}

	List left{};
	List right{};

	split(list, &left, &right);

	mergeSort(&left, byName);
	mergeSort(&right, byName);

	if (byName)
	{
		mergeByName(list, &left, &right);
	}
	else
	{
		mergeByNumber(list, &left, &right);
	}
}

void printList(List *list)
{
	Node *temp = list->head;

	while (temp != nullptr)
	{
		std::cout << temp->name << " | " << temp->number << std::endl;
		temp = temp->next;
	}
}
