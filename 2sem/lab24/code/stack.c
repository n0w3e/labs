#include "stack.h"
#include <stdlib.h>
#include <stdio.h>

void initStack(Stack *stack, int size) {
    stack->data = (double *)malloc(size * sizeof(double));
    stack->size = size;
    stack->top = -1;
}

void push(Stack *stack, double value) {
    if (stack->top < stack->size - 1) {
        stack->data[++stack->top] = value;
    } else {
        printf("Stack overflow\n");
    }
}

double pop(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top--];
    } else {
        printf("Stack underflow\n");
        return -1;
    }
}

double peek(Stack *stack) {
    if (stack->top >= 0) {
        return stack->data[stack->top];
    } else {
        printf("Stack is empty\n");
        return -1;
    }
}

int isEmpty(Stack *stack) {
    return stack->top == -1;
}

void freeStack(Stack *stack) {
    free(stack->data);
}
