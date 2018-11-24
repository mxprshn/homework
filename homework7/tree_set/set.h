#pragma once
#include <vector>

struct Set;

//get pointer to the new set
Set *createSet();

//check existence of value in the set
bool exists(Set *set, const int targetValue);

//add a new value to the set
bool add(Set *set, const int newValue);

//remove a value from the set
bool remove(Set *set, const int targetValue);

//check the set for emptiness
bool isEmpty(Set *set);

//get vector of elements in ascending order
std::vector<int> ascendingOrder(Set *set);

//get vector of elements in descending order
std::vector<int> descendingOrder(Set *set);

//delete the set completely
void deleteSet(Set *&set);
