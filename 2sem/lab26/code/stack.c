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

// Вспомогательная функция для сортировки Хоара
int hoarePartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while (1) {
        do {
            i++;
        } while (arr[i] < pivot);

        do {
            j--;
        } while (arr[j] > pivot);

        if (i >= j) {
            return j;
        }

        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

// Вспомогательная функция для сортировки Хоара
void hoareQuickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = hoarePartition(arr, low, high);
        hoareQuickSort(arr, low, pi);
        hoareQuickSort(arr, pi + 1, high);
    }
}

void quickSortStack(Stack *stack) {
    if (!isEmpty(stack)) {
        // Применяем сортировку Хоара к данным стека
        hoareQuickSort(stack->data, 0, stack->top);
    }
}
