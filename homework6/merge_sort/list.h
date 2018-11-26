#pragma once
#include <string>

struct List;
struct Node;

//get pointer to the first element of list
Node *head(List *list);

//get pointer to the last element of list
Node *tail(List *list);

//get pointer to the next element of list
Node *next(Node *current);

//get pointer to the previous element of list
Node *previous(Node *current);

//get name by the pointer to the element
std::string name(Node *node);

//get number by the pointer to the element
std::string number(Node *node);

//copy number and name from source element to target element
void copyRecord(Node *&source, Node *&target);

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

//print all the records
void printList(List *list);
