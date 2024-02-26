#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{   
    enum State {
        SEARCH_DIGIT,
        FINISH
    } state = SEARCH_DIGIT;

    printf("Введите число: ");
    long int num;
    scanf("%ld", &num);
    

    int lastDigit = num % 10;
    num /= 10;
    int secondLastDigit = num % 10;
    num /= 10;

    if (num == 0) {
        printf("Ничего не нашлось!\n");
    } else {
        printf("Тройки цифр для данного числа:\n");
    }

    while (state != FINISH) {
        switch (state) {
            case SEARCH_DIGIT:
                while (num > 0) {
                    int currentDigit = num % 10;
                    if (currentDigit < secondLastDigit && secondLastDigit < lastDigit) {
                        printf("%d%d%d\n", currentDigit, secondLastDigit, lastDigit);
                    }
                    
                    lastDigit = secondLastDigit;
                    secondLastDigit = currentDigit;
                    num /= 10;
                }
                state = FINISH;
                break;
            case FINISH:
                break;
        }   
    }
}
