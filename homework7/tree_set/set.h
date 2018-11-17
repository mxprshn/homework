#pragma once

struct Set;

//get pointer to the new set
Set *createSet();

//check existence of value in the set
bool exists(Set *set, int targetValue);

//add a new value to the set
bool add(Set *set, int newValue);

//remove a value from the set
bool remove(Set *set, int targetValue);

//check the set for emptiness
bool isEmpty(Set *set);

//print all elements of the set in ascending order
bool ascendingPrint(Set *set);

//print all elements of the set in descending order
bool descendingPrint(Set *set);

//delete the set completely
void deleteSet(Set *&set);
