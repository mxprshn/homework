#include <iostream>
#include <vector>

int main()
{
	int vertexAmount = 0;
	int edgesAmount = 0;	

	std::cout << "Enter amount of vertices: ";
	std::cin >> vertexAmount;

	std::cout << "Enter amount of edges: ";
	std::cin >> edgesAmount;

	std::cout << "Enter the matrix: " << std::endl;

	std::vector<std::vector<int>> graph(vertexAmount);

	for (unsigned int i = 0; i < vertexAmount; ++i)
	{
		graph[i].resize(edgesAmount);
	}

	for (int i = 0; i < vertexAmount; ++i)
	{
		for (int j = 0; j < edgesAmount; ++j)
		{
			std::cin >> graph[i][j];
		}
	}

	for (int i = 0; i < vertexAmount; ++i)
	{
		bool isConnected = true;

		for (int j = 0; j < edgesAmount; ++j)
		{
			if (graph[i][j] == 0)
			{
				isConnected = false;
			}
		}

		if (isConnected)
		{
			std::cout << i << ' ';
		}
	}

	return 0;
}

