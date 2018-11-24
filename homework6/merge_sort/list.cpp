#include "list.h"
#include <iostream>

struct Node
{
	std::string name;
	std::string number;
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

Node *head(List *list)
{
	return list->head;
}

Node *tail(List *list)
{
	return list->tail;
}

Node *next(Node *current)
{
	return current->next;
}

Node *previous(Node *current)
{
	return current->previous;
}

std::string name(Node *node)
{
	return node->name;
}

std::string number(Node *node)
{
	return node->number;
}

int listLength(List *list)
{
	return list->length;
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

void printList(List *list)
{
	Node *temp = list->head;

	while (temp != nullptr)
	{
		std::cout << temp->name << " | " << temp->number << std::endl;
		temp = temp->next;
	}
}
