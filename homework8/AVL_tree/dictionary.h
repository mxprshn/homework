#pragma once
#include <string>

struct Dictionary;

Dictionary *newDictionary();

//creates new dictionary and returns pointer to it
bool isEmpty(Dictionary *dictionary);

//checks a key for existence in dictionary
bool exists(Dictionary *dictionary, const std::string &targetKey);

//returns value by its key
std::string value(Dictionary *dictionary, const std::string &targetKey);

//adds a new value to dictionary
void add(Dictionary *dictionary, const std::string &key, const std::string &newValue);

//removes a key from dictionary
bool remove(Dictionary *dictionary, const std::string &targetKey);

//deletes dictionary completely
void deleteDictionary(Dictionary *&dictionary);
