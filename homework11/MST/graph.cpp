#include "graph.h"
#include <vector>
#include <algorithm>

struct Graph
{
	std::vector<std::vector<int>> edges;
};

Graph *newGraph()
{
	return new Graph;
}

bool exists(Graph *graph, const unsigned int vertex)
{
	return vertex > graph->edges.size();
}

void addEdge(Graph *graph, const unsigned int vertexA, const unsigned int vertexB, const int length)
{
	const unsigned int maxVertex = std::max(vertexA, vertexB);

	if (maxVertex >= graph->edges.size())
	{
		graph->edges.resize(maxVertex + 1);

		for (size_t i = 0; i < graph->edges.size(); ++i)
		{
			graph->edges[i].resize(maxVertex + 1, 0);
		}
	}

	graph->edges[vertexA][vertexB] = length;
}

int length(Graph *graph, const unsigned int vertexA, const unsigned int vertexB)
{
	if ((!exists(graph, vertexA)) || (!exists(graph, vertexB)))
	{
		return -1;
	}

	return graph->edges[vertexA][vertexB];
}

std::vector<int> adjacent(Graph *graph, const unsigned int vertex)
{
	std::vector<int> result;

	if (!exists(graph, vertex))
	{
		return result;
	}

	for (size_t i = 0; i < graph->edges[vertex].size(); ++i)
	{
		if (graph->edges[vertex][i] > 0)
		{
			result.push_back(i);
		}
	}

	return result;
}

bool isAdjacent(Graph *graph, const unsigned int vertexA, const unsigned int vertexB)
{
	return graph->edges[vertexA][vertexB] != 0;
}

void deleteGraph(Graph *&graph)
{
	delete graph;
	graph = nullptr;
}