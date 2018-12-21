#include "graph.h"
#include "graphReading.h"
#include <fstream>
#include <vector>

Graph *readIncidenceMatrix(const std::vector<std::vector<int>> &matrix)
{
	Graph *result = newGraph();

	for (size_t i = 0; i < matrix[0].size(); ++i)
	{
		short int vertexFrom = 0;
		short int vertexTo = 0;
		bool isFromRead = false;
		bool isBiderectional = false;

		for (size_t j = 0; j < matrix.size(); ++j)
		{
			if ((matrix[j][i] > 0) && (!isFromRead))
			{
				vertexFrom = (int)j;
				isFromRead = true;
			}
			else if (matrix[j][i] > 0)
			{
				vertexTo = (int)j;
				isBiderectional = true;
			}
			else if (matrix[j][i] < 0)
			{
				vertexTo = (int)j;
			}
		}

		addEdge(result, vertexFrom, vertexTo);

		if (isBiderectional)
		{
			addEdge(result, vertexTo, vertexFrom);
		}
	}

	return result;
}