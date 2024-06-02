#include <stdio.h>
#include "stack.h"

int main() {
    // Создание стека с максимальной вместимостью 10 элементов
    Stack *stack = createStack(10);

    // Заполнение стека элементами
    push(stack, 3);
    push(stack, 3);
    push(stack, 7);
    push(stack, 1);
    push(stack, 5);
    push(stack, 8);

    printf("Stack before sorting:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");

    // Сортировка стека
    quickSortStack(stack);

    printf("Stack after sorting:\n");
    for (int i = 0; i <= stack->top; i++) {
        printf("%d ", stack->data[i]);
    }
    printf("\n");

    // Освобождение памяти стека
    destroyStack(stack);

    return 0;
}
