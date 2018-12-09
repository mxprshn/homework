#include "list.h"

struct Node
{
	int value = 0;
	Node *previous = nullptr;
	Node *next = nullptr;
};

struct List
{
	Node *head = nullptr;
	Node *tail = nullptr;
	int length = 0;
};

int value(const Node *targetNode)
{
	return targetNode->value;
}

List *createList()
{
	return new List;
}

Node *head(const List *list)
{
	return list->head;
}

Node *tail(const List *list)
{
	return list->tail;
}

Node *next(const Node *current)
{
	return current->next;
}

Node *previous(const Node *current)
{
	return current->previous;
}

int listLength(const List *list)
{
	return list->length;
}

bool isEmpty(const List *list)
{
	return (list->length == 0);
}

void add(List *list, const int value)
{
	list->head = new Node{ value, nullptr, list->head };

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
	while (list->head != list->tail)
	{
		const Node *temp = list->head;
		list->head = list->head->next;
		delete temp;
	}

	delete (list->head);
	delete list;
	list = nullptr;
}


