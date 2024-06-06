#ifndef STACK_H
#define STACK_H

typedef struct Stack {
    double *data;
    int size;
    int top;
} Stack;

void initStack(Stack *stack, int size);
void push(Stack *stack, double value);
double pop(Stack *stack);
double peek(Stack *stack);
int isEmpty(Stack *stack);
void freeStack(Stack *stack);

#endif // STACK_H
