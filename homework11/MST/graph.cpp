#include <vector>
#include <unordered_map>
#include <iostream>
#include <iomanip>

struct Graph
{
	std::vector<std::vector<int>> edges;
	std::unordered_map<int, size_t> vertices;
};

Graph *newGraph()
{
	return new Graph;
}

bool exists(Graph *graph, const int vertex)
{
	return graph->vertices.count(vertex) != 0;
}

void addVertex(Graph *graph, const int vertex)
{
	graph->vertices.insert({vertex, graph->vertices.size()});
	graph->edges.resize(graph->vertices.size());

	for (size_t i = 0; i < graph->vertices.size(); ++i)
	{
		graph->edges[i].resize(graph->vertices.size(), 0);
	}
}

void addEdge(Graph *graph, const int vertexA, const int vertexB, const int newLength)
{
	if (!exists(graph, vertexA))
	{
		addVertex(graph, vertexA);
	}

	if (!exists(graph, vertexB))
	{
		addVertex(graph, vertexB);
	}

	graph->edges[graph->vertices[vertexA]][graph->vertices[vertexB]] = newLength;
	graph->edges[graph->vertices[vertexB]][graph->vertices[vertexA]] = newLength;
}

std::vector<int> adjacent(Graph *graph, const int vertex)
{
	std::vector<int> adjacentNodes;

	if (graph->vertices.count(vertex) == 0)
	{
		return adjacentNodes;
	}

	for (size_t i = 0; i < graph->edges.size(); ++i)
	{
		if (graph->edges[graph->vertices[vertex]][i] != 0)
		{
			adjacentNodes.push_back(i);
		}
	}

	return adjacentNodes;
}

int edgeLength(Graph *graph, const int vertexA, const int vertexB)
{
	if ((!exists(graph, vertexA)) || (!exists(graph, vertexB)))
	{
		return -1;
	}

	return graph->edges[graph->vertices[vertexA]][graph->vertices[vertexB]];
}

bool isAdjacent(Graph *graph, const int vertexA, const int vertexB)
{
	return edgeLength(graph, vertexA, vertexB) > 0;
}

void deleteGraph(Graph *&graph)
{
	delete graph;
	graph = nullptr;
}

void printGraph(Graph *graph)
{
	std::cout << std::setw(5) << std::left << ' ';

	for (std::pair<int, size_t> current : graph->vertices)
	{
		std::cout << std::setw(3) << std::left << current.first;
	}

	std::cout << std::endl;
	std::cout << std::setw(5) << ' ';

	for (size_t i = 0; i < graph->vertices.size(); ++i)
	{
		std::cout << std::setw(3) << std::setfill('_') << '_';
	}

	std::cout << std::endl << std::setfill(' ');

	for (std::pair<int, size_t> current : graph->vertices)
	{
		std::cout << std::setw(4) << current.first;
		std::cout << '|';

		for (int i : graph->edges[current.second])
		{
			std::cout << std::setw(3) << i;
		}
		std::cout << std::left;
		std::cout << std::endl;
	}
}