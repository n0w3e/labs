#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "iterator.h"

void printMenu() {
    printf("Выберите действие:\n");
    printf("1. Печать списка.\n");
    printf("2. Вставка нового элемента в список.\n");
    printf("3. Удаление элемента из списка.\n");
    printf("4. Подсчет длины списка.\n");
    printf("5. Обменять местами 2-й и предпоследний элемент списка.\n");
    printf("0. Выход.\n");
}

int main() {
    List list;
    list.head = NULL;
    int choice, data;

    do {
        printMenu();
        printf("Введите номер действия: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: {
                printf("Список: ");
                Iterator *iter = iter_create(&list);
                Node *node;
                while ((node = iter_next(iter)) != NULL) {
                    printf("%d -> ", node->data);
                }
                printf("NULL\n");
                iter_delete(iter);
                break;
            }
            case 2:
                printf("Введите значение для вставки: ");
                scanf("%d", &data);
                insertNode(&(list.head), data);
                break;
            case 3:
                printf("Введите значение для удаления: ");
                scanf("%d", &data);
                deleteNode(&(list.head), data);
                break;
            case 4:
                printf("Длина списка: %d\n", listLength(list.head));
                break;
            case 5:
                swapSecondAndPenultimate(list.head);
                printf("Обмен 2-го и предпоследнего элемента выполнен.\n");
                break;
            case 0:
                printf("Выход из программы.\n");
                break;
            default:
                printf("Неверный выбор. Пожалуйста, попробуйте снова.\n");
                break;
        }

    } while (choice != 0);

    // Освобождение памяти
    while (list.head != NULL) {
        Node* temp = list.head;
        list.head = list.head->next;
        free(temp);
    }

    return 0;
}
