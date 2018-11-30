#pragma once
#include <string>

struct List;
struct Node;

//remove node from the list
void removeNode(List *list, const Node *targetNode);

//get pointer to the node with value or null pointer if it doesn't exist
Node *exists(const List *list, const int targetValue);

//get value by pointer to node
int value(const Node *targetNode);

//get pointer to the first element of list
Node *head(const List *list);

//get pointer to the last element of list
Node *tail(const List *list);

//get pointer to the next element of list
Node *next(const Node *current);

//get pointer to the previous element of list
Node *previous(const Node *current);

//create a new list and get pointer to it
List *createList();

//get the length of list
int listLength(const List *list);

//check the list for emptiness
bool isEmpty(const List *list);

//add a new value to the list
void add(List *list, const int value);

//delete list completely
void deleteList(List *&list);
