#include <vector>
#include <unordered_map>
#include <iostream>
#include <fstream>
#include <limits>
#include "graph.h"
#include "tests.h"

struct Country
{
	std::vector<int> cities;
	bool isComplete = false;
};

std::vector<Country> fileReading(Graph *graph)
{
	std::vector<Country> countries;
	std::ifstream input("input.txt", std::ios::in);

	if (!input.is_open())
	{
		return countries;
	}

	int citiesAmount = 0;
	input >> citiesAmount;

	int roadsAmount = 0;
	input >> roadsAmount;

	for (int i = 0; i < roadsAmount; ++i)
	{
		int vertexA = 0;
		int vertexB = 0;
		int roadLength = 0;

		input >> vertexA >> roadLength >> vertexB;

		addEdge(graph, vertexA, vertexB, roadLength);
	}

	int capitalsAmount = 0;
	input >> capitalsAmount;

	for (int i = 0; i < capitalsAmount; ++i)
	{
		int capital = 0;
		input >> capital;
		assign(graph, capital);
		countries.push_back({{capital}, false});
	}

	input.close();

	return countries;
}

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

bool addCity(Graph *graph, std::vector<int> &cities)
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

bool incompleteExist(std::vector<Country> &countries)
{
	for (Country current : countries)
	{
		if (!current.isComplete)
		{
			return true;
		}
	}

	return false;
}

int main()
{
	if (!programTest())
	{
		std::cout << "Test failed." << std::endl;
		return 1;
	}
	else
	{
		std::cout << "Test completed." << std::endl;
	}

	Graph *graph = newGraph();

	std::vector<Country> countries = fileReading(graph);

	while (incompleteExist(countries))
	{
		for (Country &current : countries)
		{
			if (!current.isComplete)
			{
				current.isComplete = addCity(graph, current.cities);
			}
		}
	}

	std::cout << std::endl;

	for (int i = 0; i < countries.size(); ++i)
	{
		std::cout << "Country: " << i + 1 << " | Cities: ";

		for (int current : countries[i].cities)
		{
			std::cout << current << ' ';
		}

		std::cout << std::endl;
	}

	delete graph;
	return 0;
}