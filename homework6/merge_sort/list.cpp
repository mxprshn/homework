#include "list.h"

struct Node
{
	std::string name{};
	std::string number{};
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

void add(List *list, std::string name, std::string number)
{
	list->head = new Node{ name, number, list->head };

	if (isEmpty(list))
	{
		list->tail = list->head;
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

void split(List *list, List &left, List &right)
{
	left.head = list->head;
	left.tail = list->head;
	right.head = list->head->next;
	right.tail = list->tail;

	for (int i = 1; i < (list->length) / 2; ++i)
	{
		left.tail = left.tail->next;
		right.head = right.head->next;
	}

	left.length = (list->length) / 2;
	right.length = list->length - left.length;
}

void mergeByName(List *list, List *left, List *right)
{
	Node *temp = list->head;
	Node *tempLeft = left->head;
	Node *tempRight = right->head;

	for (int i = 1; i <= list->length; ++i)
	{
		if (tempLeft->name.compare(tempRight->name) < 0)
		{
			
		}
	}
}

void mergeSort(List *list)
{
	if (list->length == 1)
	{
		return;
	}

	List left{};
	List right{};
	split(list, left, right);
	mergeSort(&left);
	mergeSort(&right);
	mergeByName(list, &left, &right);
}
