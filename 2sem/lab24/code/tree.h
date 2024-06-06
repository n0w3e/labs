#ifndef TREE_H
#define TREE_H

typedef struct TreeNode {
    char op;
    union {
        double numValue;
        char varValue;
    };
    int isVariable;
    struct TreeNode *left, *right;
} TreeNode;

TreeNode* createNode(char op, double value);
void inorderTraversal(TreeNode *root);
void lexicographicalSort(TreeNode *root);
TreeNode* constructTree(char *expression);
void freeTree(TreeNode *root);

#endif // TREE_H
