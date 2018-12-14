#pragma once
#include <string>

struct List;
struct Node;

//mark the node value as rehashed or not
void markRehashed(Node *targetNode, const bool condition);

//check if the node value is rehashed
bool isRehashed(const Node *targetNode);

//remove node from the list
void removeNode(List *list, const Node *targetNode);

//increase amount by pointer
void addExisting(Node *targetNode);

//get pointer to the node with word or null pointer if it doesn't exist
Node *exists(const List *list, const std::string &targetWord);

//get word by pointer to node
std::string word(const Node *targetNode);

//get amount by pointer to node
int amount(const Node *targetNode);

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

//add a new word and its amount to the list
void addNew(List *list, const std::string &word, const int amount);

//delete list completely
void deleteList(List *&list);
