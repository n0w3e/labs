#include <stdio.h>
#include <stdlib.h>
#include "iterator.h"

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
    return -1; // Или другое значение по умолчанию
}

void iter_delete(Iterator *iter) {
    free(iter);
}
