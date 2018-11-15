#pragma once
#include <string>

struct List;

//create a new list and get pointer to it
List *createList();

//get the length of list
int listLength(List *list);

//check the list for emptiness
bool isEmpty(List *list);

//add new record to the list
void add(List *list, const std::string &name, const std::string &number);

//delete list completely
void deleteList(List *&list);

//sort list (by name if "byName" = true, else by number)
void mergeSort(List *list, bool byName);

//print all the records
void printList(List *list);

//check if list is sorted by name
bool checkSortByName(List *list);

//check if list is sorted by number
bool checkSortByNumber(List *list);