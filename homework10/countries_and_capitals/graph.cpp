#include <vector>
#include <unordered_map>

struct Vertex
{
	int index = 0;
	bool belongs = false;
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

void assign(Graph *graph, const int vertex)
{
	if (graph->vertices.count(vertex) == 0)
	{
		return;
	}

	graph->vertices[vertex].belongs = true;
}

bool belongs(Graph *graph, const int vertex)
{
	if (graph->vertices.count(vertex) == 0)
	{
		return 0;
	}

	return graph->vertices[vertex].belongs;
}

void addVertex(Graph *graph, const int vertex)
{
	graph->vertices.insert(std::pair<int, Vertex>(vertex, { graph->vertexAmount, false }));
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

int edgeLength(Graph *graph, const int vertexA, const int vertexB)
{
	if ((graph->vertices.count(vertexA) == 0) || (graph->vertices.count(vertexB) == 0))
	{
		return 0;
	}

	return graph->edges[graph->vertices[vertexA].index][graph->vertices[vertexB].index];
}