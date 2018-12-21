#include "priorityQueue.h"
#include <iostream>
#include <string>

int main()
{
	PriorityQueue *queue = newQueue();

	std::cout << "1 - enqueue; 2 - dequeue; 0 - exit" << std::endl;

	std::string command = "";
	while (command != "0")
	{
		std::cout << "Enter command: ";
		std::cin >> command;

		if (command == "1")
		{
			int key = 0;
			int value = 0;
			std::cout << "Enter key: ";
			std::cin >> key;
			std::cout << "Enter value: ";
			std::cin >> value;
			enqueue(queue, key, value);
		}
		else if (command == "2")
		{
			std::cout << "Value with maximum key: " << dequeue(queue) << std::endl;
		}
	}
	
	deleteQueue(queue);
	return 0;
}