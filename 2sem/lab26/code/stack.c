#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

// Создание нового стека
Stack* createStack(int capacity) {
    Stack *stack = (Stack*)malloc(sizeof(Stack));
    stack->data = (int*)malloc(capacity * sizeof(int));
    stack->top = -1;
    stack->capacity = capacity;
    return stack;
}

// Освобождение памяти стека
void destroyStack(Stack *stack) {
    free(stack->data);
    free(stack);
}

// Проверка, заполнен ли стек
bool isFull(Stack *stack) {
    return stack->top == stack->capacity - 1;
}

// Проверка, пуст ли стек
bool isEmpty(Stack *stack) {
    return stack->top == -1;
}

// Добавление элемента в стек
void push(Stack *stack, int item) {
    if (isFull(stack)) {
        printf("Stack is full\n");
        return;
    }
    stack->data[++stack->top] = item;
}

// Удаление элемента из стека
int pop(Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1;
    }
    return stack->data[stack->top--];
}

// Вспомогательная функция для быстрой сортировки
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] > pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i + 1];
    arr[i + 1] = arr[high];
    arr[high] = temp;
    return (i + 1);
}

// Вспомогательная функция для быстрой сортировки
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

void quickSortStack(Stack *stack) {
    if (!isEmpty(stack)) {
        // Применяем быструю сортировку к данным стека
        quickSort(stack->data, 0, stack->top);
        // После сортировки, инвертируем порядок элементов в стеке, чтобы получить возрастающую сортировку
        int size = stack->top + 1;
        for (int i = 0; i < size / 2; i++) {
            int temp = stack->data[i];
            stack->data[i] = stack->data[size - i - 1];
            stack->data[size - i - 1] = temp;
        }
    }
}