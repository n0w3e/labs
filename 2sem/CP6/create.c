#include "repository.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXAMS 6
#define MAXCHAR 20

void init_student(Student *s) {
    memset(s->surname, 0, MAXCHAR);
    memset(s->initials, 0, MAXCHAR);
    memset(s->sex, 0, MAXCHAR);
    memset(s->group, 0, MAXCHAR);
    s->tests = NULL;
    s->count = 0;
}

void init_test(test *t) {
    memset(t->name, 0, MAXCHAR);
    t->score = 0;
}

int main() {
    FILE *f;
    f = fopen("/home/n0wee/Coding/labs/2sem/CP6/BD.bin", "wb");
    if (f == NULL) {
        printf("Failed to open file for writing.\n");
        return 1;
    }

    char male_surnames[][MAXCHAR] = {"Fadeev", "Jilin", "Mamontov", "Ignatyev", "Subotin", "Gorohov", "Kirilov", "Sokolov", "Basharov", "Makarov", "Ivanov"};
    char female_surnames[][MAXCHAR] = {"Fadeeva", "Jilina", "Mamontova", "Ignatyeva", "Subotina", "Gorohova", "Kirilova", "Sokolova", "Basharova", "Makarova", "Ivanova"};
    char initials[][MAXCHAR] = {"DV", "MD", "PV", "ES", "MS", "DG", "KA", "VV", "DS", "MM", "TO"};
    char group[][MAXCHAR] = {"M103", "M108", "M105"};
    char exam[][MAXCHAR] = {"Math", "Rus", "History", "OOP", "Python", "Java"};
    
    srand(time(NULL));
    
    for (int i = 0; i < 11; i++) {
        Student *s = malloc(sizeof(Student));
        if (s == NULL) {
            printf("Memory allocation failed.\n");
            fclose(f);
            return 1;
        }

        init_student(s);

        int is_male = rand() % 2;
        if (is_male) {
            strcpy(s->surname, male_surnames[rand() % 11]);
            strcpy(s->sex, "M");
        } else {
            strcpy(s->surname, female_surnames[rand() % 11]);
            strcpy(s->sex, "Ж");
        }
        strcpy(s->initials, initials[rand() % 11]);
        strcpy(s->group, group[rand() % 3]);

        int count = rand() % 4 + 1;
        s->tests = malloc(count * sizeof(test *));
        if (s->tests == NULL) {
            printf("Memory allocation failed.\n");
            free(s);
            fclose(f);
            return 1;
        }

        for (int j = 0; j < count; j++) {
            s->tests[j] = malloc(sizeof(test));
            if (s->tests[j] == NULL) {
                printf("Memory allocation failed.\n");
                for (int k = 0; k < j; k++) {
                    free(s->tests[k]);
                }
                free(s->tests);
                free(s);
                fclose(f);
                return 1;
            }
            init_test(s->tests[j]);
            strcpy(s->tests[j]->name, exam[rand() % MAX_EXAMS]);
            s->tests[j]->score = rand() % 3 + 3;
        }
        s->count = count;
        add_student(s, f);

        for (int j = 0; j < count; j++) {
            free(s->tests[j]);
        }
        free(s->tests);
        free(s);
    }
    
    fclose(f);
    return 0;
}
