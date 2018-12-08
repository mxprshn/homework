
struct Node
{
	int key = 0;
	int value = 0;
	Node *next = nullptr;
};

struct PriorityQueue
{
	Node *minimum = nullptr;
};

bool isEmpty(PriorityQueue *queue)
{
	return (queue->minimum == nullptr);
}

void enqueue(PriorityQueue *queue, const int newKey, const int newValue)
{
	const auto newElement = new Node{ newKey, newValue, nullptr };

	if (isEmpty(queue))
	{
		queue->minimum = newElement;
	}
	else
	{
		Node *leftNode = nullptr;
		Node *rightNode = queue->minimum;

		while ((rightNode != nullptr) && (newElement->key > rightNode->key))
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
			newElement->next = queue->minimum;
			queue->minimum = newElement;
		}		
	}	
}

void deleteQueue(PriorityQueue *&queue)
{
	while (!isEmpty(queue))
	{
		const Node *temp = queue->minimum;
		queue->minimum = queue->minimum->next;
		delete temp;
	}

	delete queue;
	queue = nullptr;
}

int dequeue(PriorityQueue *queue, bool &result)
{
	if (queue->minimum != nullptr)
	{
		const int minimumValue = queue->minimum->value;
		Node *temp = queue->minimum;
		queue->minimum = queue->minimum->next;
		delete temp;
		return minimumValue;
	}

	result = false;
	return -1;
}

PriorityQueue *newQueue()
{
	return new PriorityQueue;
}