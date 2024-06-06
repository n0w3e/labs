#include "tree.h"
#include "tools.h"
#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdint.h>

TreeNode* createNode(char op, double value) {
    TreeNode *node = (TreeNode *)malloc(sizeof(TreeNode));
    node->op = op;
    if (op == 0) {
        node->numValue = value;
        node->isVariable = 0;
    } else if (op == 'v') {
        node->varValue = (char)value;
        node->isVariable = 1;
    } else {
        node->isVariable = 0;
    }
    node->left = node->right = NULL;
    return node;
}

void inorderTraversal(TreeNode *root) {
    if (root) {
        inorderTraversal(root->left);
        if (root->op && root->op != 'v') {
            printf("%c ", root->op);
        } else if (root->isVariable) {
            printf("%c ", root->varValue);
        } else {
            printf("%.0lf ", root->numValue);
        }
        inorderTraversal(root->right);
    }
}

int compareNodes(const void *a, const void *b) {
    TreeNode *nodeA = *(TreeNode **)a;
    TreeNode *nodeB = *(TreeNode **)b;

    if (nodeA->isVariable && nodeB->isVariable) {
        return nodeA->varValue - nodeB->varValue;
    } else if (!nodeA->isVariable && !nodeB->isVariable) {
        return (nodeA->numValue < nodeB->numValue) ? -1 : ((nodeA->numValue > nodeB->numValue) ? 1 : 0);
    } else if (nodeA->isVariable) {
        return -1;
    } else {
        return 1;
    }
}

void lexicographicalSort(TreeNode *root) {
    if (root == NULL) return;

    if (root->op == '+' || root->op == '*') {
        TreeNode *nodes[2];
        int count = 0;

        if (root->left != NULL) nodes[count++] = root->left;
        if (root->right != NULL) nodes[count++] = root->right;

        qsort(nodes, count, sizeof(TreeNode *), compareNodes);

        root->left = nodes[0];
        if (count > 1) root->right = nodes[1];
    }

    lexicographicalSort(root->left);
    lexicographicalSort(root->right);
}

TreeNode* constructTree(char *expression) {
    Stack operators;
    Stack operands;
    initStack(&operators, strlen(expression));
    initStack(&operands, strlen(expression));

    for (int i = 0; i < strlen(expression); i++) {
        if (isspace(expression[i])) continue;

        if (isdigit(expression[i])) {
            double value = 0;
            while (i < strlen(expression) && isdigit(expression[i])) {
                value = value * 10 + (expression[i] - '0');
                i++;
            }
            i--;
            TreeNode *node = createNode(0, value);
            push(&operands, (double)(uintptr_t)node);
        } else if (isalpha(expression[i])) {
            TreeNode *node = createNode('v', expression[i]);
            push(&operands, (double)(uintptr_t)node);
        } else if (isOperator(expression[i])) {
            while (!isEmpty(&operators) && precedence(peek(&operators)) >= precedence(expression[i])) {
                char op = (char)pop(&operators);
                TreeNode *right = (TreeNode *)(uintptr_t)pop(&operands);
                TreeNode *left = (TreeNode *)(uintptr_t)pop(&operands);
                TreeNode *node = createNode(op, 0);
                node->left = left;
                node->right = right;
                push(&operands, (double)(uintptr_t)node);
            }
            push(&operators, expression[i]);
        }
    }

    while (!isEmpty(&operators)) {
        char op = (char)pop(&operators);
        TreeNode *right = (TreeNode *)(uintptr_t)pop(&operands);
        TreeNode *left = (TreeNode *)(uintptr_t)pop(&operands);
        TreeNode *node = createNode(op, 0);
        node->left = left;
        node->right = right;
        push(&operands, (double)(uintptr_t)node);
    }

    TreeNode *root = (TreeNode *)(uintptr_t)pop(&operands);
    freeStack(&operators);
    freeStack(&operands);
    return root;
}

void freeTree(TreeNode *root) {
    if (root) {
        freeTree(root->left);
        freeTree(root->right);
        free(root);
    }
}
