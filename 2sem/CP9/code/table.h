// File: table.h

#ifndef TABLE_H
#define TABLE_H

#include "str.h"

#define MAX_TABLE_SIZE 10

typedef struct {
    Record elements[MAX_TABLE_SIZE];
    int size;
} Table;

void initializeTable(Table *table);
void printTable(const Table *table);
void tournamentSort(Table *table);
int binarySearch(const Table *table, const char *key);

#endif // TABLE_H
