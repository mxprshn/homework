#include "priorityQueue.h"
#include <vector>
#include <algorithm>

struct QueueElement
{
	int key = 0;
	std::pair<int, int> value;
};

struct PriorityQueue
{
	std::vector<QueueElement> elements;
};

PriorityQueue *newQueue()
{
	return new PriorityQueue;
}

void swapElements(QueueElement &elementA, QueueElement &elementB)
{
	const int tempKey = elementA.key;
	const std::pair<int, int> tempValue = elementA.value;
	elementA.key = elementB.key;
	elementA.value = elementB.value;
	elementB.key = tempKey;
	elementB.value = tempValue;
}

void upHeap(PriorityQueue *queue, size_t position)
{
	while ((position != 0) && (queue->elements[position].key < queue->elements[(position - 1) / 2].key))
	{
		swapElements(queue->elements[position], queue->elements[(position - 1) / 2]);
		position = (position - 1) / 2;
	}
}

void downHeap(PriorityQueue *queue, size_t position)
{
	while ((position * 2 + 1) < queue->elements.size())
	{
		int minChild = position * 2 + 1;

		if ((position * 2 + 2 < queue->elements.size()) && (queue->elements[position * 2 + 2].key < queue->elements[position * 2 + 1].key))
		{
			minChild = position * 2 + 2;
		}

		swapElements(queue->elements[minChild], queue->elements[position]);
		position = minChild;
	}
}

void enqueue(PriorityQueue *queue, const int newKey, const std::pair<int, int> &newValue)
{
	queue->elements.push_back({newKey, newValue});
	upHeap(queue, queue->elements.size() - 1);
}

std::pair<int, int> dequeue(PriorityQueue *queue)
{
	const std::pair<int, int> minimum = queue->elements[0].value;
	swapElements(queue->elements[0], queue->elements[queue->elements.size() - 1]);
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
