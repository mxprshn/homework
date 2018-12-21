#include "priorityQueue.h"
#include <vector>
#include <algorithm>

struct PriorityQueue
{
	std::vector<std::pair<int, int>> elements;
};

PriorityQueue *newQueue()
{
	return new PriorityQueue;
}

void upHeap(PriorityQueue *queue, size_t position)
{
	while ((position != 0) && (queue->elements[position].first >= queue->elements[(position - 1) / 2].first))
	{
		swap(queue->elements[position], queue->elements[(position - 1) / 2]);
		position = (position - 1) / 2;
	}
}

void downHeap(PriorityQueue *queue, size_t position)
{
	while ((position * 2 + 1) < queue->elements.size())
	{
		int maxChild = position * 2 + 1;
		if ((position * 2 + 2 < queue->elements.size()) && (queue->elements[position * 2 + 2].first > queue->elements[position * 2 + 1].first))
		{
			maxChild = position * 2 + 2;
		}

		if (queue->elements[maxChild].first < queue->elements[position].first)
		{
			break;
		}

		swap(queue->elements[maxChild], queue->elements[position]);
		position = maxChild;
	}

	if (position + 1 < queue->elements.size() && (queue->elements[position].first == queue->elements[position + 1].first))
	{
		swap(queue->elements[position], queue->elements[position + 1]);
	}
}

void enqueue(PriorityQueue *queue, const int key, const int value)
{
	std::pair<int, int> newElement = {key, value};

	//if (!isEmpty(queue) && key == queue->elements[0].first)
	//{
	//	queue->elements.insert(queue->elements.begin(), newElement);
	//	return;
	//}

	queue->elements.push_back(newElement);
	upHeap(queue, queue->elements.size() - 1);
}

int dequeue(PriorityQueue *queue)
{
	if (isEmpty(queue))
	{
		return -1;
	}

	const std::pair<int, int> maximum = queue->elements[0];
	swap(queue->elements[0], queue->elements[queue->elements.size() - 1]);
	queue->elements.pop_back();
	downHeap(queue, 0);
	return maximum.second;
}

bool isEmpty(PriorityQueue *queue)
{
	return queue->elements.size() == 0;
}

void deleteQueue(PriorityQueue *&queue)
{
	delete queue;
	queue = nullptr;
}
