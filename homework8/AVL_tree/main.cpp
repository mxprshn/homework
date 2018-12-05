#include "dictionary.h"
#include "user.h"

int main()
{
	Dictionary *dictionary = newDictionary();
	userInterface(dictionary);
	deleteDictionary(dictionary);
	return 0;
}