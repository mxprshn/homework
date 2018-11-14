#include "list.h"

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

	for (int i = (list->length); i >= 1; --i)
	{
		if (i > ((list->length) / 2) + 1)
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

void mergeByName(List *list, List &left, List &right)
{
	Node *temp = list->head;
	Node *tempLeft = left.head;
	Node *tempRight = right.head;

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
	split(list, &left, &right);
	mergeSort(&left);
	mergeSort(&right);
//	mergeByName(list, &left, &right);
}
