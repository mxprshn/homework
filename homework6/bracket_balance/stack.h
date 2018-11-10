#pragma once

struct Stack;

//add a new element on the top of the stack
void push(Stack *stack, int value);

//get value of the upper element and remove it from the stack
int pop(Stack *stack, bool &result);

//check the stack for emptiness
bool isEmpty(Stack *stack);

//delete the stack completely
void deleteStack(Stack *&stack);

//create a new stack
Stack *createStack();

