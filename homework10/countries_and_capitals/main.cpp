#include <vector>
#include <unordered_map>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <limits>
#include "graph.h"

void findClosest(Graph *graph, const int city, int &minLength, int &closestCity)
{
	for (int current : adjacent(graph, city))
	{
		const int distance = edgeLength(graph, city, current);
		if ((distance < minLength) && (!belongs(graph, current)))
		{
			minLength = edgeLength(graph, city, current);
			closestCity = current;
		}
	}
}

bool addCity(Graph *graph, const int country, std::vector<int> &cities)
{
	int minLength = std::numeric_limits<int>::max();
	int closestCity = -1;

	for (int currentCity : cities)
	{
		findClosest(graph, currentCity, minLength, closestCity);
	}

	if (closestCity >= 0)
	{
		assign(graph, closestCity);
		cities.push_back(closestCity);
	}

	return (closestCity < 0);
}

bool incompleteExist(std::vector<bool> &isComplete)
{
	for (bool currentComplete : isComplete)
	{
		if (!currentComplete)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	std::ifstream input("input.txt", std::ios::in);

	if (!input.is_open())
	{
		return 1;
	}

	Graph *graph = newGraph();

	int citiesAmount = 0;
	input >> citiesAmount;

	int roadsAmount = 0;
	input >> roadsAmount;

	for (int i = 0; i < roadsAmount; ++i)
	{
		int vertexA = 0;
		int vertexB = 0;
		int roadLength = 0;

		input >> vertexA;
		input >> roadLength;
		input >> vertexB;

		addEdge(graph, vertexA, vertexB, roadLength);
	}

	int capitalsAmount = 0;
	input >> capitalsAmount;
	std::vector<std::vector<int>> countries;
	std::vector<bool> isComplete;

	for (int i = 1; i < capitalsAmount + 1; ++i)
	{
		int capital = 0;
		input >> capital;
		assign(graph, capital);
		countries.push_back({ capital });
		isComplete.push_back(false);
	}

	input.close();

	while (incompleteExist(isComplete))
	{
		for (int i = 0; i < capitalsAmount; ++i)
		{
			if (!isComplete[i])
			{
				isComplete[i] = addCity(graph, i + 1, countries[i]);
			}
		}
	}

	printGraph(graph);
	delete graph;
	return 0;
}