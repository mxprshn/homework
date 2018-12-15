#pragma once
#include <vector>

struct PriorityQueue;

//returns pointer to the new queue
PriorityQueue *newQueue();

//adds a new element to the queue (newElement.first = key, newElement.second = value)
void enqueue(PriorityQueue *queue, const std::pair<int, int> &newElement);

//returns the minimum element in the queue and removes it
std::pair<int, int> dequeue(PriorityQueue *queue);

//checks the queue for emptiness
bool isEmpty(PriorityQueue *queue);

//deletes the queue completely
void deleteQueue(PriorityQueue *&queue);