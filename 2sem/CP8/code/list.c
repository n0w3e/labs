#include <stdio.h>
#include <stdlib.h>
#include "list.h"
#include "iterator.h"

// Создание нового узла
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Печать списка
void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Вставка нового элемента в начало списка
void insertNode(Node** head, int data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

// Удаление элемента из списка
void deleteNode(Node** head, int data) {
    Node* current = *head;
    Node* previous = NULL;
    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }
    if (current != NULL) {
        if (previous == NULL) {
            *head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Подсчет длины списка
int listLength(Node* head) {
    int length = 0;
    Node* current = head;
    while (current != NULL) {
        length++;
        current = current->next;
    }
    return length;
}

// Обмен 2-го и предпоследнего элемента
void swapSecondAndPenultimate(Node* head) {
    if (head == NULL || head->next == NULL) {
        return;
    }

    if (head->next->next == NULL) {
        Node* first = head;
        Node* second = head->next;
        int temp = first->data;
        first->data = second->data;
        second->data = temp;
        return;
    }

    Node* second = head->next;
    Node* penultimate = head;
    Node* previous = NULL;

    while (penultimate->next->next != NULL) {
        previous = penultimate;
        penultimate = penultimate->next;
    }

    // Обмен данных между вторым и предпоследним элементами
    int temp = second->data;
    second->data = penultimate->data;
    penultimate->data = temp;
}

Iterator *iter_create(List *list) {
    Iterator *iter = (Iterator *)malloc(sizeof(Iterator));
    if (!iter) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }
    iter->node = list->head;
    return iter;
}

Node *iter_next(Iterator *iter) {
    if (iter->node == NULL) return NULL;
    Node *current = iter->node;
    iter->node = iter->node->next;
    return current;
}

void iter_set(Iterator *iter, int value) {
    if (iter->node != NULL) {
        iter->node->data = value;
    }
}

int iter_get(Iterator *iter) {
    if (iter->node != NULL) {
        return iter->node->data;
    }
    return -1;
}

void iter_delete(Iterator *iter) {
    free(iter);
}
