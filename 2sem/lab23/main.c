#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *parent;
    struct Node *child;
    struct Node *sibling;
};

struct Node* createNode(int data, struct Node *parent) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("Ошибка выделения памяти\n");
        exit(1);
    }
    newNode->data = data;
    newNode->parent = parent;
    newNode->child = NULL;
    newNode->sibling = NULL;
    return newNode;
}

void addChild(struct Node *parent, int data) {
    struct Node* newNode = createNode(data, parent);
    if (parent->child == NULL) {
        parent->child = newNode;
    } else {
        struct Node* sibling = parent->child;
        while (sibling->sibling != NULL) {
            sibling = sibling->sibling;
        }
        sibling->sibling = newNode;
    }
}


void deleteSubtree(struct Node *parent, struct Node *node) {
    if (node == NULL) return;
    
    if (parent == NULL) {
        deleteSubtree(NULL, node->child);
        deleteSubtree(NULL, node->sibling);
        free(node);
    } else {
        if (parent->child == node) {
            parent->child = NULL;
        } else {
            struct Node *sibling = parent->child;
            while (sibling->sibling != node) {
                sibling = sibling->sibling;
            }
            sibling->sibling = node->sibling;
        }
        deleteSubtree(NULL, node->child);
        deleteSubtree(NULL, node->sibling);
        free(node);
    }
}

void deleteRoot(struct Node **root) {
    if (*root == NULL) return;

    deleteSubtree(NULL, (*root)->child);
    free(*root);
    *root = NULL;
}

void printTree(struct Node *node, int depth) {
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%d\n", node->data);
    printTree(node->child, depth + 1);
    printTree(node->sibling, depth);
}

int maxDepth = 0;

void findMaxDepth(struct Node *node, int depth) {
    if (node == NULL) {
        return;
    }
    if (depth > maxDepth) {
        maxDepth = depth;
    }
    findMaxDepth(node->child, depth + 1);
    findMaxDepth(node->sibling, depth);
}


int main() {
    struct Node* root = NULL;

    int rootData;
    printf("Введите значение корневой вершины: ");
    scanf("%d", &rootData);
    root = createNode(rootData, NULL);

    int choice;
    do {
        printf("\nМеню:\n");
        printf("1. Добавить узел\n");
        printf("2. Вывести дерево\n");
        printf("3. Удалить поддерево\n");
        printf("4. Найти глубину максимальной вершины\n");
        printf("5. Удалить корневую вершину и все поддеревья\n");
        printf("6. Выход\n");
        printf("Выберите действие: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1: {
                int parentData, newData;
                printf("Введите значение родительского узла: ");
                scanf("%d", &parentData);
                printf("Введите значение нового узла: ");
                scanf("%d", &newData);
                
                struct Node *foundParent = NULL;
                
                void findParent(struct Node *node, int data) {
                    if (node == NULL || foundParent != NULL) return;
                    if (node->data == data) {
                        foundParent = node;
                        return;
                    }
                    findParent(node->child, data);
                    findParent(node->sibling, data);
                }
                
                findParent(root, parentData);
                
                if (foundParent == NULL) {
                    printf("Родительский узел не найден\n");
                } else {
                    addChild(foundParent, newData);
                    printf("Узел успешно добавлен\n");
                }
                break;
            }

            case 2: {
                printf("Дерево:\n");
                printTree(root, 0);
                break;
            }
            case 3: {
                printf("Введите значение узла, поддерево которого нужно удалить: ");
                int deleteData;
                scanf("%d", &deleteData);

                struct Node *deleteNode = NULL;
                struct Node *parentNode = NULL;

                void findDeleteNode(struct Node *node, int data, struct Node *parent) {
                    if (node == NULL || deleteNode != NULL) return;
                    if (node->data == data) {
                        deleteNode = node;
                        parentNode = parent;
                        return;
                    }
                    findDeleteNode(node->child, data, node);
                    findDeleteNode(node->sibling, data, parent);
                }

                findDeleteNode(root, deleteData, NULL);

                if (deleteNode == NULL) {
                    printf("Узел для удаления не найден\n");
                } else {
                    if (parentNode == NULL) {
                        printf("Нельзя удалить корневую вершину с помощью этой кнопки\n");
                    } else {
                        deleteSubtree(parentNode, deleteNode);
                        printf("Поддерево удалено\n");
                    }
                }
                break;
            }

            case 4: {
                maxDepth = 0;
                findMaxDepth(root, 0);
                printf("Глубина максимальной вершины: %d\n", maxDepth);
                break;
            }
            case 5: {
                printf("Удалить корневую вершину и все поддеревья (y/n): ");
                char answer;
                scanf(" %c", &answer);
                if (answer == 'y' || answer == 'Y') {
                    deleteRoot(&root);
                    printf("Дерево успешно удалено\n");
                    
                    printf("Введите значение новой корневой вершины: ");
                    scanf("%d", &rootData);
                    root = createNode(rootData, NULL);
                }
                break;
            }
            case 6: {
                printf("Выход из программы\n");
                break;
            }
            default: {
                printf("Неверный ввод\n");
                break;
            }
        }
    } while (choice != 6);

    deleteSubtree(NULL, root);

    return 0;
}
