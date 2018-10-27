#pragma once

struct SortedList;

//check the list for emptiness
bool isEmpty(SortedList *list);

//add a new element to the sorted list
void insert(SortedList *list, int newValue);

//delete the sorted list completely
void deleteList(SortedList *list);

//delete a node of specific position from the sorted list
bool deleteNode(SortedList *list, int targetPosition);

//print the sorted list completely with position numbers
void printList(SortedList *list);

//create a new sorted list
SortedList *createList();

//check the list for sorting
bool checkSorting(SortedList *list);