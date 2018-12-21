#include "graph.h"
#include <vector>
#include <unordered_map>

struct Graph
{
	std::vector<std::vector<int>> edges;
	std::unordered_map<int, size_t> vertices;
};

Graph *newGraph()
{
	return new Graph;
}

void deleteGraph(Graph *&graph)
{
	delete graph;
	graph = nullptr;
}

bool exists(Graph *graph, const int vertex)
{
	return graph->vertices.count(vertex) != 0;
}

void addVertex(Graph *graph, const int newVertex)
{
	graph->vertices.insert({newVertex, graph->edges.size()});
	graph->edges.resize(graph->edges.size() + 1);
}

void addEdge(Graph *graph, const int vertexFrom, const int vertexTo)
{
	if (!exists(graph, vertexFrom))
	{
		addVertex(graph, vertexFrom);
	}

	if (!exists(graph, vertexTo))
	{
		addVertex(graph, vertexTo);
	}

	graph->edges[graph->vertices[vertexFrom]].push_back(vertexTo);
}

std::vector<int> adjacent(Graph *graph, const int vertex)
{
	std::vector<int> result;

	if (!exists(graph, vertex))
	{
		return result;
	}

	for (int current : graph->edges[graph->vertices[vertex]])
	{
		result.push_back(current);
	}

	return result;
}