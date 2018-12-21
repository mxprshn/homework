#pragma once
#include <vector>
#include <fstream>

//reads graph from incidence matrix
Graph *readIncidenceMatrix(const std::vector<std::vector<int>> &matrix);