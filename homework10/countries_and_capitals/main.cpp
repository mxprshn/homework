#include <vector>
#include <iostream>
#include <fstream>
#include "graph.h"
#include "tests.h"
#include "priorityQueue.h"

struct Country
{
	std::vector<int> cities;
	PriorityQueue *toAdd;
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
		countries.push_back({{capital}, newQueue()});

		for (int current : adjacent(graph, capital))
		{
			enqueue(countries[i].toAdd, edgeLength(graph, capital, current), current);
		}
	}

	input.close();

	return countries;
}

void addCity(Graph *graph, std::vector<int> &cities, PriorityQueue *toAdd)
{
	bool result = true;
	int closestCity = dequeue(toAdd, result);

	while (belongs(graph, closestCity) && result)
	{
		closestCity = dequeue(toAdd, result);
	}	

	if (result)
	{
		assign(graph, closestCity);
		cities.push_back(closestCity);

		for (int current : adjacent(graph, closestCity))
		{
			enqueue(toAdd, edgeLength(graph, closestCity, current), current);
		}
	}
}

bool incompleteExist(std::vector<Country> &countries)
{
	for (Country current : countries)
	{
		if (!isEmpty(current.toAdd))
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
			if (!isEmpty(current.toAdd))
			{
				addCity(graph, current.cities, current.toAdd);
			}
		}
	}

	std::cout << std::endl;

	for (size_t i = 0; i < countries.size(); ++i)
	{
		std::cout << "Country: " << i + 1 << " | Cities: ";

		for (int current : countries[i].cities)
		{
			std::cout << current << ' ';
		}

		std::cout << std::endl;
	}

	for (Country current : countries)
	{
		deleteQueue(current.toAdd);
	}

	deleteGraph(graph);

	return 0;
}