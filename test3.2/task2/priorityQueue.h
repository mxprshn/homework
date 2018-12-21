#pragma once

struct PriorityQueue;

//check the queue for emptiness
bool isEmpty(PriorityQueue *queue);

//add a new element to the queue
void enqueue(PriorityQueue *queue, const int newKey, const int newValue);

//delete the queue completely
void deleteQueue(PriorityQueue *&queue);

//qet the minimum value from the queue and remove it
int dequeue(PriorityQueue *queue);

//create a new queue
PriorityQueue *newQueue();