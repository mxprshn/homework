#include "priorityQueue.h"
#include "graph.h"
#include <fstream>
#include <vector>
#include <iostream>

bool fileReading(std::ifstream &file, Graph *graph)
{
	int vertexAmount = 0;
	file >> vertexAmount;

	for (int i = 0; i < vertexAmount; ++i)
	{
		for (int j = 0; j < vertexAmount; ++j)
		{
			if (file.eof())
			{
				return false;
			}

			int length = 0;
			file >> length;
			addEdge(graph, i, j, length);
		}
	}

	return true;
}

Graph *findMST(Graph *graph, const unsigned int startVertex)
{
	Graph *result = newGraph();

	PriorityQueue *edgesQueue = newQueue();

	for (int i : adjacent(graph, startVertex))
	{
		enqueue(edgesQueue, edgeLength(graph, startVertex, i), {startVertex, i});
	}

	while (!isEmpty(edgesQueue))
	{
		const std::pair<int, int> shortestEdge = dequeue(edgesQueue);

		if (!exists(result, shortestEdge.second))
		{
			addEdge(result, shortestEdge.first, shortestEdge.second, edgeLength(graph, shortestEdge.first, shortestEdge.second));

			for (int i : adjacent(graph, shortestEdge.second))
			{
				if (!exists(result, i))
				{
					enqueue(edgesQueue, edgeLength(graph, shortestEdge.second, i), {shortestEdge.second, i});
				}
			}
		}
	}

	return result;
}

int main()
{
	std::ifstream input("input.txt", std::ios::in);

	Graph *graph = newGraph();
	fileReading(input, graph);
	printGraph(graph);
	std::cout << std::endl;
	printGraph(findMST(graph, 0));
	return 0;
}