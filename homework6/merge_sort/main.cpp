#include "list.h"
#include <iostream>
#include <fstream>

int main()
{
	std::ifstream file("input.txt", std::ios::in);

	List *myList = createList();

	mergeSort(myList, false);
	printList(myList);

	deleteList(myList);
	return 0;
}