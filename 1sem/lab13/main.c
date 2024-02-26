#include <stdio.h>
#include <string.h>
#include <ctype.h>

int BitMasks(char* word1, char* word2) {
    int mask1 = 0;
    int mask2 = 0;

    for (int i = 0; i < strlen(word1); i++) {
        if (isalpha(word1[i])) {
            mask1 |= 1 << (tolower(word1[i]) - 'a');
        }
    }

    for (int i = 0; i < strlen(word2); i++) {
        if (isalpha(word2[i])) {
            mask2 |= 1 << (tolower(word2[i]) - 'a');
        }
    }

    return mask1 == mask2;
}

int main() {
    char input[100];
    printf("Введите строку: ");
    fgets(input, 100, stdin);

    char* token = strtok(input, " ,\t\n");
    int numWords = 0;
    char words[10][20];

    while (token != NULL && numWords < 10) {
        strcpy(words[numWords], token);
        numWords++;
        token = strtok(NULL, " ,\t\n");
    }

    int k = 0;
    for (int i = 0; i < numWords - 1; i++) {
        if (BitMasks(words[i], words[i + 1])) {
            printf("Слова '%s' и '%s' содержат одинаковые наборы букв\n", words[i], words[i + 1]);
            k++;
        }
    }

    if (k == 0) {
        printf("В данной строке нет слов с одинаковым набором букв\n");
    }

    return 0;
}