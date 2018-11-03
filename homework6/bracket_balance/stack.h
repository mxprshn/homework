#pragma 

struct Stack;

void push(Stack *stack, int value);
int pop(Stack *stack, bool &result);
bool isEmpty(Stack *stack);
void deleteStack(Stack *stack);
Stack *createStack();

