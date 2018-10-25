#pragma once

struct Node
{
	int value = 0;
	int position = 0;
	Node *next = nullptr;
};

struct SortedList
{
	Node *minimum = nullptr;
};

bool isEmpty(SortedList list);
void insert(SortedList &list, int newValue);
void deleteList(SortedList &list);
bool deleteNode(SortedList &list, int targetPosition);
void printList(SortedList &list);
