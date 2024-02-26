#include <stdio.h>

int main()
{
    int size;
    printf("Введите размер квадратной матрицы: ");
    scanf("%d", &size);
    
    if (size == 0) {
        printf("NET\n");
    }
    
    int matrix[7][7];
    if (size != 0) {
        printf("Введите элементы матрицы:\n");
    }
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    if (size == 1) {
        printf("%d\n", matrix[0][0]);
    }

    enum State { 
        START,
        FIRST, 
        DIAG_UP1,
        DIAG_UP2,
        UP,    
        DIAG_DOWN1,
        DIAG_DOWN2,
        DOWN,
        RIGHT,
        FINISH,
    } state = START;
            
    int i, j, upper, downer;  
            
    while (state != FINISH && size != 0 && size != 1) 
    {                
        switch (state)  
        {
            case START:
                i = 0;
                j = size - 1;
                downer = size;
                upper = size;
                printf("%d ", matrix[i][j]);
                state = FIRST;
                break;

            case FIRST:
                for (int c = 0; c < size - 1; c++) {
                    i++;
                    j--;
                    printf("%d ", matrix[i][j]);
                }
                int oldi = i;
                int oldj = j;
                state = UP;
                break;

            case UP:
                i--;
                if (i == 0 && j == 0) {
                    printf("%d ", matrix[i][j]);
                    printf("%d\n", matrix[size - 1][size - 1]);
                    state = FINISH;
                    break;
                } else {
                    printf("%d ", matrix[i][j]);
                    state = DIAG_UP1;
                    break;
                }
            
            case RIGHT:
                i = oldi;
                j = oldj;
                j++;
                printf("%d ", matrix[i][j]);
                state = DIAG_UP2;
                break;
            
            case DIAG_UP1:
                for (int c = 0; c < upper - 2; c++) {
                    i--;
                    j++;
                    printf("%d ", matrix[i][j]);
                }
                int oldest_i = i;
                int oldest_j = j - 1;
                state = RIGHT;
                break;
            
            case DIAG_UP2:
                for (int c = 0; c < upper - 2; c++) {
                    i--;
                    j++;
                    printf("%d ", matrix[i][j]);
                }
                upper--;
                state = DOWN;
                break;

            case DOWN:
                i++;
                printf("%d ", matrix[i][j]);
                state = DIAG_DOWN1;
                break;

            case DIAG_DOWN1:
                for (int q = 0; q < downer - 3; q++) {
                    i++;
                    j--;
                    printf("%d ", matrix[i][j]);
                }
                state = DIAG_DOWN2;
                break;

            case DIAG_DOWN2:
                printf("%d ", matrix[oldest_i][oldest_j]);
                for (int q = 0; q < downer - 3; q++) {
                    oldest_i++;
                    oldest_j--;
                    printf("%d ", matrix[oldest_i][oldest_j]);
                }
                downer--;
                i = oldest_i;
                j = oldest_j;
                if (size == 3) {
                    printf("\n");
                    state = FINISH;
                    break;
                }
                if (size == 5) {
                    i--;
                    printf("%d ", matrix[i][j]);
                    i--;
                    j++;
                    printf("%d ", matrix[i][j]);
                    printf("%d %d ", matrix[4][3], matrix[3][4]);
                    i = 1;
                    j = 0;
                    state = UP;
                    break;
                }
                if (size == 6 || size == 7) {
                    if (size == 7) {
                        i = 3;
                        j = 0;
                    } else {
                        i = 2;
                        j = 0;
                    }
                    for (int o = 0; o < 2; o++) {
                        if (size == 7) {
                            for (int p = 0; p < 4; p++) {
                            printf("%d ", matrix[i][j]);
                            i--;
                            j++;
                        }
                        i = 6;
                        j = 3;
                        } else {
                            for (int p = 0; p < 3; p++) {
                            printf("%d ", matrix[i][j]);
                            i--;
                            j++;
                        }
                        i = 5;
                        j = 3;
                        }
                    }
                    if (size == 7) {
                        i = 4;
                        j = 6;
                    } else if (size == 6) {
                        i = 4;
                        j = 5;
                    }
                    for (int h1 = 0; h1 < 2; h1++) {
                        if (size == 7) {
                            for (int h2 = 0; h2 < 3; h2++) {
                            printf("%d ", matrix[i][j]);
                            i++;
                            j--;
                        }
                        i = 0;
                        j = 2;
                        } else if (size == 6) {
                            for (int h2 = 0; h2 < 2; h2++) {
                                printf("%d ", matrix[i][j]);
                                i++;
                                j--;
                            }
                            i = 0;
                            j = 1;
                        }
                    }
                    if (size == 6) {
                        i = 1;
                        j = 0;
                        state = UP;
                        break;
                    } else {
                        i = 1;
                        j = 0;
                        for (int en1 = 0; en1 < 2; en1++) {
                            for (int en2 = 0; en2 < 2; en2++) {
                                printf("%d ", matrix[i][j]);
                                i--;
                                j++;
                            }
                            i = 6;
                            j = 5;
                        }
                        printf("%d %d\n", matrix[6][6], matrix[0][0]);
                        state = FINISH;
                        break;
                    }
                }
                state = UP;
                break;
            case FINISH:
                break;
        }
    }
}
