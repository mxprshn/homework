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
	while ((position != 0) && (queue->elements[position].first < queue->elements[(position - 1) / 2].first))
	{
		swap(queue->elements[position], queue->elements[(position - 1) / 2]);
		position = (position - 1) / 2;
	}
}

void downHeap(PriorityQueue *queue, size_t position)
{
	while ((position * 2 + 1) < queue->elements.size())
	{
		int minChild = position * 2 + 1;
		if ((position * 2 + 2 < queue->elements.size()) && (queue->elements[position * 2 + 2].first < queue->elements[position * 2 + 1].first))
		{
			minChild = position * 2 + 2;
		}

		swap(queue->elements[minChild], queue->elements[position]);
		position = minChild;
	}
}

void enqueue(PriorityQueue *queue, const std::pair<int, int> &newElement)
{
	queue->elements.push_back(newElement);
	upHeap(queue, queue->elements.size() - 1);
}

std::pair<int, int> dequeue(PriorityQueue *queue)
{
	const std::pair<int, int> minimum = queue->elements[0];
	swap(queue->elements[0], queue->elements[queue->elements.size() - 1]);
	queue->elements.pop_back();
	downHeap(queue, 0);
	return minimum;
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
