#pragma once
#include <string>
#include <vector>

struct HashTable;

//get pointer to the new hash table 
HashTable *newTable();

//get average length of list in the table
float averageLength(const HashTable *table);

//get load factor of the table
float loadFactor(const HashTable *table);

//get max length of list in the table
int maxLength(const HashTable *table);

//add a word to the table
void add(HashTable *hashTable, const std::string &word);

//delete the table completely
void deleteTable(HashTable *&table);

//check a word for existence in the table
bool wordExists(const HashTable *table, const std::string &word);

//get amount of the same words
int amountByWord(const HashTable *table, const std::string &word);