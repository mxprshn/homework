#include <vector>
#include <unordered_map>
#include <iostream>
#include <iomanip>

struct Vertex
{
	bool belongs = false;
	int length = 0;
};

struct Graph
{
	int vertexAmount = 0;
	std::vector<std::vector<Vertex>> edges;
	std::unordered_map<int, int> vertices;
};

Graph *newGraph()
{
	return new Graph;
}

void addVertex(Graph *graph, const int vertex)
{
	graph->vertices.insert(std::pair<int, int>(vertex, graph->vertexAmount));
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

	graph->edges[graph->vertices[vertexA]][graph->vertices[vertexB]].length = newLength;
	graph->edges[graph->vertices[vertexB]][graph->vertices[vertexA]].length = newLength;
}

int main()
{
	Graph *graph = newGraph();
	addEdge(graph, 1, 170, 12);
	addEdge(graph, 5, 4, 700);

	for (std::vector<Vertex> current : graph->edges)
	{
		for (Vertex currentVertex : current)
		{
			std::cout << std::setw(4) << currentVertex.length;
		}

		std::cout << std::endl;
	}
	return 0;
}