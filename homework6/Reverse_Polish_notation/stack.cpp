#include "stack.h"

struct StackElement
{
	int value = 0;
	StackElement *next = nullptr;
};

struct Stack
{
	StackElement *head = nullptr;
};

void push(Stack *stack, int value)
{
	const auto newElement = new StackElement{ value, stack->head };
	stack->head = newElement;
}

int pop(Stack *stack, bool &result)
{
	if (isEmpty(stack))
	{
		result = false;
		return -1;
	}

	const int headValue = stack->head->value;
	const auto temp = stack->head;
	stack->head = stack->head->next;
	delete temp;
	return headValue;
}

bool isEmpty(Stack *stack)
{
	return (stack->head == nullptr);
}

void deleteStack(Stack *&stack)
{
	while (!isEmpty(stack))
	{
		const auto temp = stack->head;
		stack->head = stack->head->next;
		delete temp;
	}

	delete stack;
	stack = nullptr;
}

Stack *createStack()
{
	return new Stack;
}