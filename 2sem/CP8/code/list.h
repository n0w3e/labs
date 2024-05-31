#ifndef LIST_H
#define LIST_H

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data);
void printList(Node* head);
void insertNode(Node** head, int data);
void deleteNode(Node** head, int data);
int listLength(Node* head);
void swapSecondAndPenultimate(Node* head);

#endif
