#pragma once
#include <string>

struct List;
struct Node;

Node *head(List *list);

Node *tail(List *list);

Node *next(Node *current);

Node *previous(Node *current);

std::string name(Node *node);

std::string number(Node *node);

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
void mergeSort(List *list, const bool byName);

//print all the records
void printList(List *list);

//check if list is sorted (by name if "byName" = true, else by number)
bool checkSort(List *list, const bool byName);