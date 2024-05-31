#include <stdio.h>
#include <stdlib.h>
#include "list.h"

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
    if (head == NULL || head->next == NULL || head->next->next == NULL) {
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
