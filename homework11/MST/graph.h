#pragma once
#include<vector>

struct Graph;

//create new graph and get pointer to it
Graph *newGraph();

//adds a vertex to the graph
void addVertex(Graph *graph, const int vertex);

//checks a vertex for existence in the graph
bool exists(Graph *graph, const int vertex);

//adds an edge between two vertices of the graph
void addEdge(Graph *graph, const int vertexA, const int vertexB, const int newLength);

//returns vector of adjacent vertices
std::vector<int> adjacent(Graph *graph, const int vertex);

//checks if one vertex is adjacent to another
bool isAdjacent(Graph *graph, const int vertexA, const int vertexB);

//returns length of an edge
int edgeLength(Graph *graph, const int vertexA, const int vertexB);

//deletes graph completely
void deleteGraph(Graph *&graph);

//prints graph as adjacency matrix
void printGraph(Graph *graph);
