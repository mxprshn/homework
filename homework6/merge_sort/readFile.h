#pragma once
#include "list.h"
#include <fstream>

//read list from file
bool readFile(std::ifstream &file, List *list);
