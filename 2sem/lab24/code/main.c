#include "tree.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    char expression1[] = "2 + b + c + a - a * b";
    char expression2[] = "a + 1 + d * c * b";
    char expression3[] = "5 * z + 2 * y + 3 * x";

    printf("Исходное выражение: %s\n", expression1);
    TreeNode *root1 = constructTree(expression1);
    printf("Дерево выражения (симметричный обход): ");
    inorderTraversal(root1);
    printf("\n");
    lexicographicalSort(root1);
    printf("Преобразованное дерево выражения (симметричный обход): ");
    inorderTraversal(root1);
    printf("\n\n");
    freeTree(root1);

    printf("Исходное выражение: %s\n", expression2);
    TreeNode *root2 = constructTree(expression2);
    printf("Дерево выражения (симметричный обход): ");
    inorderTraversal(root2);
    printf("\n");
    lexicographicalSort(root2);
    printf("Преобразованное дерево выражения (симметричный обход): ");
    inorderTraversal(root2);
    printf("\n\n");
    freeTree(root2);

    printf("Исходное выражение: %s\n", expression3);
    TreeNode *root3 = constructTree(expression3);
    printf("Дерево выражения (симметричный обход): ");
    inorderTraversal(root3);
    printf("\n");
    lexicographicalSort(root3);
    printf("Преобразованное дерево выражения (симметричный обход): ");
    inorderTraversal(root3);
    printf("\n\n");
    freeTree(root3);

    return 0;
}
