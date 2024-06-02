#include <stdio.h>
#include <string.h>
#include "table.h"

void initializeTable(Table *table) {
    table->size = 0;
}

void printTable(const Table *table) {
    printf("Table:\n");
    for (int i = 0; i < table->size; ++i) {
        printf("%s: %s\n", table->elements[i].key, table->elements[i].text);
    }
}

int compareKeys(const char *key1, const char *key2) {
    return strcmp(key1, key2);
}

static void swapRecords(Record *a, Record *b) {
    Record temp = *a;
    *a = *b;
    *b = temp;
}

static void tournamentSortUtil(Record *arr, int low, int high, int index) {
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    int max = index;

    if (left < high && compareKeys(arr[left].key, arr[max].key) > 0)
        max = left;

    if (right < high && compareKeys(arr[right].key, arr[max].key) > 0)
        max = right;

    if (max != index) {
        swapRecords(&arr[index], &arr[max]);
        tournamentSortUtil(arr, low, high, max);
    }
}

static void buildMaxHeap(Record *arr, int size) {
    for (int i = size / 2 - 1; i >= 0; i--) {
        tournamentSortUtil(arr, 0, size, i);
    }
}

void tournamentSort(Table *table) {
    Record *arr = table->elements;
    int size = table->size;

    buildMaxHeap(arr, size);

    for (int i = size - 1; i > 0; i--) {
        swapRecords(&arr[0], &arr[i]);
        tournamentSortUtil(arr, 0, i, 0);
    }
}

int binarySearch(const Table *table, const char *key) {
    int low = 0, high = table->size - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        int cmp = compareKeys(table->elements[mid].key, key);
        if (cmp == 0) {
            return mid; // found
        } else if (cmp < 0) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1; // not found
}
