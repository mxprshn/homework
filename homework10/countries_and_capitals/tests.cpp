#include "graph.h"

bool programTest()
{
	Graph *testGraph = newGraph();

	for (int i = 0; i < 11; ++i)
	{
		addVertex(testGraph, i * 10);
		assign(testGraph, i * 10);
	}

	for (int i = 0; i < 11; ++i)
	{
		for (int j = 0; j < 11; ++j)
		{
			if (isAdjacent(testGraph, i * 10, j * 10) || !belongs(testGraph, i * 10))
			{
				deleteGraph(testGraph);
				return false;
			}
		}
	}

	for (int i = 0; i < 11; ++i)
	{
		for (int j = i + 1; j < 11; ++j)
		{
			addEdge(testGraph, i * 10, j * 10, i + j);
		}
	}

	for (int i = 0; i < 11; ++i)
	{
		for (int j = i + 1; j < 11; ++j)
		{
			if (edgeLength(testGraph, i * 10, j * 10) != i + j)
			{
				deleteGraph(testGraph);
				return false;
			}
		}
	}

	for (int i = 0; i < 11; ++i)
	{
		for (int j : adjacent(testGraph, i * 10))
		{
			if ((j == i * 10) || (j > 100))
			{
				deleteGraph(testGraph);
				return false;
			}
		}
	}

	deleteGraph(testGraph);
	return true;
}