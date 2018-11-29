#pragma once
#include "hashTable.h"
#include <fstream>
#include <vector>
#include <string>

std::vector<std::string> readFile(std::ifstream &file, HashTable *& hashTable, std::vector<std::string> &wordVector);
