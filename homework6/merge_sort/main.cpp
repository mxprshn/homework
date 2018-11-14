#include "list.h"
#include <iostream>

struct Node;

struct List
{
	Node *head = nullptr;
	Node *tail = nullptr;
	int length = 0;
};

int main()
{
	List *myList = createList();
	add(myList, "Andrey Terekhov", "88005553535"); 
	add(myList, "Andrey Merekhov", "88005553545");
	add(myList, "Andrey Kerekhov", "88005553565");
	add(myList, "Andrey Lerekhov", "88005553525");
	add(myList, "Andrey Derekhov", "88005553525");
	List left{};
	List right{};
	List riight{};
	List leeft{};
	split(myList, &left, &right);
	split(&left, &leeft, &riight);

	deleteList(myList);
	return 0;
}