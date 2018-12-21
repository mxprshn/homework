#include "priorityQueue.h"

struct Node
{
	int key = 0;
	int value = 0;
	Node *next = nullptr;
};

struct PriorityQueue
{
	Node *maximum = nullptr;
};

bool isEmpty(PriorityQueue *queue)
{
	return (queue->maximum == nullptr);
}

void enqueue(PriorityQueue *queue, const int newKey, const int newValue)
{
	const auto newElement = new Node{ newKey, newValue, nullptr };

	if (isEmpty(queue))
	{
		queue->maximum = newElement;
	}
	else
	{
		Node *leftNode = nullptr;
		Node *rightNode = queue->maximum;

		while (rightNode != nullptr && newElement->key < rightNode->key)
		{
			leftNode = rightNode;
			rightNode = rightNode->next;
		}

		if (leftNode != nullptr)
		{
			newElement->next = rightNode;
			leftNode->next = newElement;
		}
		else
		{
			newElement->next = queue->maximum;
			queue->maximum = newElement;
		}		
	}	
}

void deleteQueue(PriorityQueue *&queue)
{
	while (!isEmpty(queue))
	{
		const Node *temp = queue->maximum;
		queue->maximum = queue->maximum->next;
		delete temp;
	}

	delete queue;
	queue = nullptr;
}

int dequeue(PriorityQueue *queue)
{
	if (queue->maximum != nullptr)
	{
		const int maximumValue = queue->maximum->value;
		Node *temp = queue->maximum;
		queue->maximum = queue->maximum->next;
		delete temp;
		return maximumValue;
	}

	return -1;
}

PriorityQueue *newQueue()
{
	return new PriorityQueue;
}