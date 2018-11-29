#include <vector>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <fstream>

struct Vertex
{
	int index = 0;
	int belongs = 0;
};

struct Graph
{
	int vertexAmount = 0;
	std::vector<std::vector<int>> edges;
	std::unordered_map<int, Vertex> vertices;
};

Graph *newGraph()
{
	return new Graph;
}

void assign(Graph *graph, const int vertex, const int target)
{
	if (graph->vertices.count(vertex) == 0)
	{
		return;
	}

	graph->vertices[vertex].belongs = target;
}

int belongs(Graph *graph, const int vertex)
{
	if (graph->vertices.count(vertex) == 0)
	{
		return 0;
	}

	return graph->vertices[vertex].belongs;
}

void addVertex(Graph *graph, const int vertex)
{
	graph->vertices.insert(std::pair<int, Vertex>(vertex, { graph->vertexAmount, 0 }));
	++graph->vertexAmount;
	graph->edges.resize(graph->vertexAmount);

	for (int i = 0; i < graph->vertexAmount; ++i)
	{
		graph->edges[i].resize(graph->vertexAmount);
	}
}

void addEdge(Graph *graph, const int vertexA, const int vertexB, const int newLength)
{
	if (graph->vertices.count(vertexA) == 0)
	{
		addVertex(graph, vertexA);
	}

	if (graph->vertices.count(vertexB) == 0)
	{
		addVertex(graph, vertexB);
	}

	graph->edges[graph->vertices[vertexA].index][graph->vertices[vertexB].index] = newLength;
	graph->edges[graph->vertices[vertexB].index][graph->vertices[vertexA].index] = newLength;
}

std::vector<int> adjacent(Graph *graph, const int vertex)
{
	std::vector<int> adjacentNodes;

	if (graph->vertices.count(vertex) == 0)
	{
		return adjacentNodes;
	}

	for (std::pair<int, Vertex> current : graph->vertices)
	{
		if (graph->edges[graph->vertices[vertex].index][current.second.index] != 0)
		{
			adjacentNodes.push_back(current.first);
		}
	}

	return adjacentNodes;
}

bool isAdjacent(Graph *graph, const int vertexA, const int vertexB)
{
	for (int i : adjacent(graph, vertexA))
	{
		if (i == vertexB)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	std::ifstream input("input.txt", std::ios::in);

	if (!input.is_open())
	{
		return 1;
	}

	Graph *graph = newGraph();

	int citiesAmount = 0;
	input >> citiesAmount;
	int roadsAmount = 0;
	input >> roadsAmount;
	
	for (int i = 0; i < roadsAmount; ++i)
	{
		int vertexA = 0;
		int vertexB = 0;
		int roadLength = 0;
		input >> vertexA;
		input >> roadLength;
		input >> vertexB;
		addEdge(graph, vertexA, vertexB, roadLength);
	}

	int capitalsAmount = 0;
	input >> capitalsAmount;

	for (int i = 1; i < capitalsAmount + 1; ++i)
	{
		int capital = 0;
		input >> capital;
		assign(graph, capital, i);
	}

	return 0;
}