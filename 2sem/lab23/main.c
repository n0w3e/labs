#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* firstChild;
    struct Node* nextSibling;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->firstChild = NULL;
    newNode->nextSibling = NULL;
    return newNode;
}

int maxDepth = 0;

void findMaxDepth(Node* node, int depth) {
    if (node == NULL) {
        return;
    }
    if (depth > maxDepth) {
        maxDepth = depth;
    }
    if (node->firstChild != NULL) {
        findMaxDepth(node->firstChild, depth + 1);
    }
    if (node->nextSibling != NULL) {
        findMaxDepth(node->nextSibling, depth);
    }
}

void freeTree(Node* node) {
    if (node == NULL) {
        return;
    }
    freeTree(node->firstChild);
    freeTree(node->nextSibling);
    free(node);
}

void createTree(Node* parent) {
    int childCount;
    printf("Сколько потомков у вершины с данными %d: ", parent->data);
    scanf("%d", &childCount);

    for (int i = 0; i < childCount; i++) {
        int childData;
        printf("Введите значение потомка %d: ", i + 1);
        scanf("%d", &childData);

        Node* newChild = createNode(childData);

        if (parent->firstChild == NULL) {
            parent->firstChild = newChild;
        } else {
            Node* temp = parent->firstChild;
            while (temp->nextSibling != NULL) {
                temp = temp->nextSibling;
            }
            temp->nextSibling = newChild;
        }

        createTree(newChild); 
    }
}

int main() {
    int rootData;
    printf("Введите значение корневой вершины: ");
    scanf("%d", &rootData);
    
    Node* root = createNode(rootData);
    
    createTree(root);

    findMaxDepth(root, 0);

    printf("Глубина максимальной вершины: %d\n", maxDepth);

    freeTree(root); // Освобождаем память

    return 0;
}
