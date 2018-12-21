#pragma once
#include <vector>

struct PriorityQueue;

//returns pointer to the new queue
PriorityQueue *newQueue();

//adds a new element to the queue
void enqueue(PriorityQueue *queue, const int key, const int value);

//returns the maximum key element in the queue and removes it
int dequeue(PriorityQueue *queue);

//checks the queue for emptiness
bool isEmpty(PriorityQueue *queue);

//deletes the queue completely
void deleteQueue(PriorityQueue *&queue);