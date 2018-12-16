#include "priorityQueue.h"
#include "graph.h"
#include <fstream>

bool fileReading(std::ifstream &file, Graph *graph)
{
	int vertexAmount = 0;
	file >> vertexAmount;

	for (int i = 0; i < vertexAmount; ++i)
	{
		for (int j = 0; j < vertexAmount; ++j)
		{
			int length = 0;
			file >> length;
			addEdge(graph, i, j, length);
		}
	}

	return true;
}

int main()
{
	std::ifstream file("input.txt", std::ios::in);
	Graph *graph = newGraph();
	fileReading(file, graph);
	return 0;
}