#include <stdio.h>
#include <stdbool.h>


int sign(int num) {
    return num > 0 ? 1 : num == 0 ? 0 : -1;
}

int max(int x, int y) {
    return x > y ? x : y;
}

int min(int x, int y) {
    return x < y ? x : y;
}


int abs(int x) {
    return x > 0 ? x : -x;
}


int main()
{
    int i0 = 10, j0 = 20, l0 = -1, i, j, l;
    int flag = 1;
    i = i0;
    j = j0;
    l = l0;
    for(int k = 0; k < 50; k++)
    {        
        if ((i <= 15 && i >= 5) && (j >= -15 && j <= -5)) 
        {
            printf("Точка попала за %d итерации(-ий).\n", k);
            flag = 1;
            break;
        } else 
        {
            i = (abs(max((i0 * (k + 5)), (j0 * (k + 6)))) - abs(min((j0 * (k + 7)), (l0 * (k + 8))))) % 20;
            j = (3 - sign(i0 - j0)) * (abs(min(min(i0 * j0 + 5, j0 * l0 - 3), i0 * j0 + 6)) % 25 - 7);
            l = (i0 % 10) + (j0 % 10) + (l0 % 10);
            printf("Координаты точки: (%d,%d); параметр движения: %d, итерация %d \n", i, j, l, k);
            flag = 0;
        }
        i0 = i;
        j0 = j;
        l0 = l;
    }
}