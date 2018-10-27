#pragma once

struct SortedList;
bool isEmpty(SortedList *list);
void insert(SortedList *list, int newValue);
void deleteList(SortedList *list);
bool deleteNode(SortedList *list, int targetPosition);
void printList(SortedList *list);
SortedList *createList();
bool checkSorting(SortedList *list);