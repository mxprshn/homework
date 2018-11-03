#define _CRT_SECURE_NO_WARNINGS
#include "cyclicList.h"

struct Node
{
	int value = 0;
	Node *next = nullptr;
};

struct CyclicList
{
	Node *current = nullptr;
	Node *previous = nullptr;
};

bool isOnly(CyclicList *list)
{
	return (list->previous == list->current);
}

bool isEmpty(CyclicList *list)
{
	return (list->current == nullptr);
}

void insert(CyclicList *list, int newValue)
{
	const auto newNode = new Node{ newValue, list->current };
	
	if (isEmpty(list))
	{
		list->current = newNode;
	}
	else
	{
		list->previous->next = newNode;
	}

	list->previous = newNode;
}

void deleteCurrent(CyclicList *list)
{
	if (isOnly(list))
	{
		delete list->current;
		list->current = nullptr;
		list->previous = nullptr;
	}
	else
	{
		const auto temp = list->current;
		list->previous->next = list->current->next;
		list->current = list->current->next;
		delete temp;
	}
}

void moveCurrent(CyclicList *list)
{
	list->previous = list->current;
	list->current = list->current->next;
}

CyclicList *createList()
{
	return new CyclicList;
}

void deleteList(CyclicList *list)
{
	while (!isOnly(list))
	{
		const auto temp = list->current;
		list->current = list->current->next;
		delete temp;
	}

	if (!isEmpty(list))
	{
		delete list->current;
	}

	delete list;
}

int currentValue(CyclicList *list)
{
	return list->current->value;
}

