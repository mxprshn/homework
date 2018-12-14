#include "list.h"

struct Node
{
	bool isRehashed = false;
	std::string word;
	int amount = 0;
	Node *previous = nullptr;
	Node *next = nullptr;
};

struct List
{
	Node *head = nullptr;
	Node *tail = nullptr;
	int length = 0;
};

void markRehashed(Node *targetNode, const bool condition)
{
	targetNode->isRehashed = condition;
}

bool isRehashed(const Node *targetNode)
{
	return targetNode->isRehashed;
}

std::string word(const Node *targetNode)
{
	return targetNode->word;
}

int amount(const Node *targetNode)
{
	return targetNode->amount;
}

void addExisting(Node *targetNode)
{
	if (targetNode != nullptr)
	{
		++targetNode->amount;
	}
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

void removeNode(List *list, const Node *targetNode)
{
	if (targetNode->previous != nullptr)
	{
		targetNode->previous->next = targetNode->next;
	}
	else
	{
		list->head = targetNode->next;
	}

	if (targetNode->next != nullptr)
	{
		targetNode->next->previous = targetNode->previous;
	}
	else
	{
		list->tail = targetNode->previous;
	}

	--list->length;
	delete targetNode;
}

Node *exists(const List *list, const std::string &targetWord) 
{
	Node *temp = list->head;

	while (temp != nullptr)
	{
		if (temp->word == targetWord)
		{
			return temp;
		}

		temp = temp->next;
	}

	return temp;
}

void addNew(List *list, const std::string &word, const int amount)
{
	list->head = new Node{ false, word, amount, nullptr, list->head };

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


