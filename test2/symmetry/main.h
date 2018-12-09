#pragma once
#include "list.h"
#include <fstream>

bool isSymmetric(List *list);
bool fileReading(std::ifstream &input, List *list);
