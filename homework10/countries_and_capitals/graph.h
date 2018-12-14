#pragma once
#include<vector>

struct Graph;

//create new graph and get pointer to it
Graph *newGraph();

//add a vertex to the graph
void addVertex(Graph *graph, const int vertex);

//add an edge between two vertices of the graph
void addEdge(Graph *graph, const int vertexA, const int vertexB, const int newLength);

//get vector of adjacent vertices
std::vector<int> adjacent(Graph *graph, const int vertex);

//check if one vertex is adjacent to another
bool isAdjacent(Graph *graph, const int vertexA, const int vertexB);

//check a vertex for belonging
bool belongs(Graph *graph, const int vertex);

//mark a vertex as belonging
void assign(Graph *graph, const int vertex);

//get length of an edge
int edgeLength(Graph *graph, const int vertexA, const int vertexB);

void deleteGraph(Graph *&graph);
