#pragma once
#include<vector>

struct Graph;

Graph *newGraph();
void addVertex(Graph *graph, const int vertex);
void addEdge(Graph *graph, const int vertexA, const int vertexB, const int newLength);
std::vector<int> adjacent(Graph *graph, const int vertex);
bool isAdjacent(Graph *graph, const int vertexA, const int vertexB);
bool belongs(Graph *graph, const int vertex);
void assign(Graph *graph, const int vertex);
int edgeLength(Graph *graph, const int vertexA, const int vertexB);
void printGraph(Graph *graph);
