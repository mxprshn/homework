#pragma once
#include "graph.h"
#include <fstream>

//reads graph as adjacency matrix from from file
bool fileReading(std::ifstream &file, Graph *graph);

//finds minimum spanning tree of the graph
Graph *findMST(Graph *graph, const unsigned int startVertex);

