#include "graph.h"
#include "graphReading.h"
#include "depthFirstSearch.h"
#include <fstream>
#include <unordered_set>
#include <iostream>

std::vector<std::vector<int>> readMatrix(std::ifstream &file)
{
	std::vector<std::vector<int>> result;

	size_t matrixHeight = 0;
	size_t matrixWidth = 0;

	file >> matrixHeight;
	file >> matrixWidth;

	result.resize(matrixHeight);

	for (size_t i = 0; i < matrixHeight; ++i)
	{
		result[i].resize(matrixWidth);

		for (size_t j = 0; j < matrixWidth; ++j)
		{
			int value = 0;
			file >> value;
			result[i][j] = value;
		}
	}

	return result;
}

int main()
{
	std::ifstream input("input.txt", std::ios::in);

	if (!input.is_open())
	{
		return 1;
	}

	std::vector<std::vector<int>> inputMatrix = readMatrix(input);
	Graph *graph = readIncidenceMatrix(inputMatrix);

	std::vector<int> visits(inputMatrix.size(), 0);

	for (size_t i = 0; i < inputMatrix.size(); ++i)
	{
		for (int i : depthFirstSearch(graph, i))
		{
			++visits[i];
		}
	}

	std::cout << "Vertices accessible from all other vertices: " << std::endl;

	for (size_t i = 0; i < visits.size(); ++i)
	{
		if (visits[i] == inputMatrix.size())
		{
			std::cout << i << std::endl;
		}
	}

	deleteGraph(graph);

	return 0;
}