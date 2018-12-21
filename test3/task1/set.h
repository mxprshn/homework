#pragma once
#include <vector>

struct Set;

//get pointer to the new set
Set *createSet();

//add a new value to the set
void add(Set *set, const int newValue);

//check the set for emptiness
bool isEmpty(Set *set);

//get vector of elements in ascending order
std::vector<std::pair<int, int>> ascendingOrder(Set *set);

//delete the set completely
void deleteSet(Set *&set);
