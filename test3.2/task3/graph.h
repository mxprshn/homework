#pragma once
#include <vector>

struct Graph;

//creates new graph
Graph *newGraph();

//deletes graph completely
void deleteGraph(Graph *&graph);

//checks if a vertex exists in the graph
bool exists(Graph *graph, const int vertex);

//adds a new vertex to the graph
void addVertex(Graph *graph, const int newVertex);

//adds a new edge to the graph
void addEdge(Graph *graph, const int vertexFrom, const int vertexTo);

//returns the vector of adjacent vertices
std::vector<int> adjacent(Graph *graph, const int vertex);

