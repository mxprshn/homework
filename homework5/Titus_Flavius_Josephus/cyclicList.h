#pragma once

struct CyclicList;

//insert an element before current
void insert(CyclicList *list, int newValue);

//delete current element without moving the previous
void deleteCurrent(CyclicList *list);

//create a new cyclic list
CyclicList *createList();

//delete the list completely
void deleteList(CyclicList *list);

//check if there's only one element in the list
bool isOnly(CyclicList *list);

//check if the list is empty
bool isEmpty(CyclicList *list);

//make the current element previous and make the next element current
void moveCurrent(CyclicList *list);

//return the value of current element
int currentValue(CyclicList *list);

