#include <stdio.h>
#include <stdlib.h>

// Структура для представления узла дерева
struct Node {
    int data;
    struct Node *parent;
    struct Node *child;
    struct Node *sibling;
};

// Создание нового узла
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

// Функция для добавления узла как дочернего к указанному родительскому узлу
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

// Функция для удаления поддерева, начиная с указанного узла
void deleteSubtree(struct Node *parent, struct Node *node) {
    if (node == NULL) return;
    
    // Если удаляемый узел - корень дерева
    if (parent == NULL) {
        deleteSubtree(NULL, node->child);
        deleteSubtree(NULL, node->sibling);
        free(node);
    } else {
        // Если удаляемый узел - дочерний узел
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

// Функция для текстовой визуализации дерева
void printTree(struct Node *node, int depth) {
    if (node == NULL) return;
    for (int i = 0; i < depth; i++) {
        printf("  ");
    }
    printf("%d\n", node->data);
    printTree(node->child, depth + 1);
    printTree(node->sibling, depth);
}

// Функция для нахождения глубины максимальной вершины
// Глобальная переменная для хранения максимальной глубины
int maxDepth = 0;

// Функция для нахождения максимальной глубины
void findMaxDepth(struct Node *node, int depth) {
    if (node == NULL) {
        return;
    }
    if (depth > maxDepth) {
        maxDepth = depth;
    }
    // Рекурсивно обходим всех дочерних узлов
    findMaxDepth(node->child, depth + 1);
    // Рекурсивно обходим всех сестринских узлов
    findMaxDepth(node->sibling, depth);
}


int main() {
    struct Node* root = NULL;

    // Функция для ввода пользователем корневой вершины дерева
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
        printf("5. Выйти\n");
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
                
                // Функция поиска родительского узла во всем дереве
                void findParent(struct Node *node, int data) {
                    if (node == NULL || foundParent != NULL) return;
                    if (node->data == data) {
                        foundParent = node;
                        return;
                    }
                    findParent(node->child, data);
                    findParent(node->sibling, data);
                }
                
                // Начинаем поиск с корня дерева
                findParent(root, parentData);
                
                if (foundParent == NULL) {
                    printf("Родительский узел не найден\n");
                } else {
                    // Добавляем новый узел к найденному родительскому узлу
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

                // Функция поиска узла для удаления
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

                // Начинаем поиск с корня дерева
                findDeleteNode(root, deleteData, NULL);

                if (deleteNode == NULL) {
                    printf("Узел для удаления не найден\n");
                } else {
                    if (parentNode == NULL) {
                        deleteSubtree(NULL, deleteNode);
                    } else {
                        deleteSubtree(parentNode, deleteNode);
                    }
                    printf("Поддерево удалено\n");
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
                printf("Выход из программы\n");
                break;
            }
            default: {
                printf("Неверный ввод\n");
                break;
            }
        }
    } while (choice != 5);

    // Удаление дерева перед завершением программы
    deleteSubtree(NULL, root);

    return 0;
}
