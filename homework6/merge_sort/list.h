#pragma once
#include <string>

struct List;

List *createList();
bool isEmpty(List *list);
void add(List *list, const std::string &name, const std::string &number);
void deleteList(List *&list);
void mergeSort(List *list, bool byName);
void printList(List *list);
