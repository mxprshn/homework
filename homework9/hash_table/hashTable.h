#pragma once
#include <string>
#include <vector>

struct HashTable;

//get pointer to the new hash table 
HashTable *newTable();

//get average length of list in the table
float averageLength(const HashTable *hashTable);

//get load factor of the table
float loadFactor(const HashTable *hashTable);

//get max length of list in the table
int maxLength(const HashTable *hashTable);

//add a word to the table
void add(HashTable *hashTable, const std::string &word);

//delete the table completely
void deleteTable(HashTable *&hashTable);

//check a word for existence in the table
bool wordExists(const HashTable *hashTable, const std::string &word);

//get amount of the same words
int amountByWord(const HashTable *hashTable, const std::string &word);