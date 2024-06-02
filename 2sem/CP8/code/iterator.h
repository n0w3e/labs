#ifndef ITERATOR_H
#define ITERATOR_H

#include "list.h"

typedef struct {
    Node *node;
} Iterator;

Iterator *iter_create(List *list);
Node *iter_next(Iterator *iter);

void iter_set(Iterator *iter, int value);
int iter_get(Iterator *iter);
void iter_delete(Iterator *iter);

#endif
