#include "programTest.h"
#include "main.h"
#include "graph.h"
#include <fstream>

bool programTest()
{	
	std::ifstream testFile("test.txt", std::ios::in);
	if (!testFile.is_open())
	{
		return false;
	}

	Graph *testGraph = newGraph();

	if (!fileReading(testFile, testGraph))
	{
		deleteGraph(testGraph);
		return false;
	}

	Graph *sampleTree = newGraph();

	if (!fileReading(testFile, sampleTree))
	{
		deleteGraph(testGraph);
		deleteGraph(sampleTree);
		return false;
	}

	const int startVertex1 = 0;
	const int startVertex2 = 3;
	const int startVertex3 = 5;
	const int vertexAmount = 7;

	Graph *spanningTree1 = findMST(testGraph, startVertex1);
	Graph *spanningTree2 = findMST(testGraph, startVertex2);
	Graph *spanningTree3 = findMST(testGraph, startVertex3);

	deleteGraph(testGraph);

	for (int i = 0; i < vertexAmount; ++i)
	{
		for (int j = 0; j < vertexAmount; ++j)
		{
			if (edgeLength(spanningTree1, i, j) != edgeLength(sampleTree, i, j))
			{
				deleteGraph(spanningTree1);
				deleteGraph(spanningTree2);
				deleteGraph(spanningTree3);
				deleteGraph(sampleTree);
				return false;
			}

			if (edgeLength(spanningTree2, i, j) != edgeLength(sampleTree, i, j))
			{
				deleteGraph(spanningTree1);
				deleteGraph(spanningTree2);
				deleteGraph(spanningTree3);
				deleteGraph(sampleTree);
				return false;
			}

			if (edgeLength(spanningTree3, i, j) != edgeLength(sampleTree, i, j))
			{
				deleteGraph(spanningTree1);
				deleteGraph(spanningTree2);
				deleteGraph(spanningTree3);
				deleteGraph(sampleTree);
				return false;
			}
		}
	}

	deleteGraph(spanningTree1);
	deleteGraph(spanningTree2);
	deleteGraph(spanningTree3);
	deleteGraph(sampleTree);
	return true;
}