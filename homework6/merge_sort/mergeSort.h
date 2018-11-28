#pragma once
#include "list.h"

//sort list (by name if "byName" = true, else by number)
void mergeSort(List *list, const bool byName);

//check if list is sorted (by name if "byName" = true, else by number)
bool checkSort(List *list, const bool byName);
