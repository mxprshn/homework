#pragma once
#include <vector>

struct Graph;

//returns pointer to the new graph
Graph *newGraph();

//checks a vertex for existence in the graph
bool exists(Graph *graph, const unsigned int vertex);

//adds a new edge between vertexA and vertexB to the graph
void addEdge(Graph *graph, const unsigned int vertexA, const unsigned int vertexB, const int length);

//returns the length of edge between vertexA and vertexB
int length(Graph *graph, const unsigned int vertexA, const unsigned int vertexB);

//returns vector of adjacent vertices
std::vector<int> adjacent(Graph *graph, const unsigned int vertex);

//checks if one vertex is adjacent to another
bool isAdjacent(Graph *graph, const unsigned int vertexA, const unsigned int vertexB);

//deletes the graph completely
void deleteGraph(Graph *&graph);