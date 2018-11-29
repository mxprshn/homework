#pragma once
#include "hashTable.h"
#include <fstream>
#include <vector>
#include <string>

//add words from file to the hash table and return vector of them
std::vector<std::string> readFile(std::ifstream &file, HashTable *& hashTable);