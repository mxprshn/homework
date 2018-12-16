#pragma once
#include<vector>

struct Graph;

//create new graph and get pointer to it
Graph *newGraph();

//add a vertex to the graph
void addVertex(Graph *graph, const int vertex);

//check a vertex for existence in the graph
bool exists(Graph *graph, const int vertex);

//add an edge between two vertices of the graph
void addEdge(Graph *graph, const int vertexA, const int vertexB, const int newLength);

//get vector of adjacent vertices
std::vector<int> adjacent(Graph *graph, const int vertex);

//check if one vertex is adjacent to another
bool isAdjacent(Graph *graph, const int vertexA, const int vertexB);

//get length of an edge
int edgeLength(Graph *graph, const int vertexA, const int vertexB);

//delete graph completely
void deleteGraph(Graph *&graph);

void printGraph(Graph *graph);
