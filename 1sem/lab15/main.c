#include <stdio.h>

void findMinMax(int matrix[][100], int size, int *min, int *max) {
    *min = matrix[0][0];
    *max = matrix[0][0];

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] < *min) {
                *min = matrix[i][j];
            }
            if (matrix[i][j] > *max) {
                *max = matrix[i][j];
            }
        }
    }
}

void replaceMaxWithMinCols(int matrix[][100], int size) {
    int min, max;
    findMinMax(matrix, size, &min, &max);

    int countMin = 0;
    for (int j = 0; j < size; j++) {
        for (int i = 0; i < size; i++) {
            if (matrix[i][j] == min) {
                countMin++;
            }
        }
    }

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (matrix[i][j] == max) {
                matrix[i][j] = countMin;
            }
        }
    }
}

void printMatrix(int matrix[][100], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main(void) {
    int size;
    printf("Введите размер квадратной матрицы: ");
    scanf("%d", &size);

    int matrix[100][100];

    if (size != 0){
        printf("Введите элементы матрицы %dx%d:\n", size, size);
    } else {
        printf("Некорректный ввод!\n");
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }

    replaceMaxWithMinCols(matrix, size);

    if (size != 0) {
        printf("\nМатрица после изменений:\n");
    }

    printMatrix(matrix, size);

    return 0;
}
