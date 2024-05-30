#ifndef STACK_H
#define STACK_H

#include <stdbool.h>

// Тип данных для стека
typedef struct {
    int *data;      // Указатель на массив данных
    int top;        // Индекс вершины стека
    int capacity;   // Максимальная вместимость стека
} Stack;

// Функции для работы со стеком
Stack* createStack(int capacity);
void destroyStack(Stack *stack);
bool isFull(Stack *stack);
bool isEmpty(Stack *stack);
void push(Stack *stack, int item);
int pop(Stack *stack);
void quickSortStack(Stack *stack);

#endif // STACK_H
