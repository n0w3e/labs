#include <stdio.h>

void swapColumns(int size, int matrix[size][size], int col1, int col2) {
    for (int i = 0; i < size; i++) {
        int temp = matrix[i][col1];
        matrix[i][col1] = matrix[i][col2];
        matrix[i][col2] = temp;
    }
}

int main(void) {
    int size;

    printf("Введите размер квадратной матрицы: ");
    scanf("%d", &size);

    int matrix[size][size];

    printf("Введите элементы матрицы %dx%d:\n", size, size);
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    int colSums[size];

    for (int j = 0; j < size; j++) {
        colSums[j] = 0;
        for (int i = 0; i < size; i++) {
            colSums[j] += matrix[i][j];
        }
    }

    int maxSumIndex = 0;
    int minSumIndex = 0;

    for (int j = 1; j < size; j++) {
        if (colSums[j] > colSums[maxSumIndex]) {
            maxSumIndex = j;
        }
        if (colSums[j] < colSums[minSumIndex]) {
            minSumIndex = j;
        }
    }

    swapColumns(size, matrix, maxSumIndex, minSumIndex);

    printf("Матрица после перестановки столбцов:\n");
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    return 0;
}
