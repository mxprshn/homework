#include "priorityQueue.h"

int main()
{
	PriorityQueue *queue = newQueue();
	enqueue(queue, {4, 339});
	enqueue(queue, { -1, 339 });
	enqueue(queue, { 0, 339 });
	enqueue(queue, { 122, 339 });
	enqueue(queue, { -44, 339 });
	enqueue(queue, { -1, 339 });
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	dequeue(queue);
	deleteQueue(queue);

	return 0;
}