#include "repository.h"
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EXAMS 6

int main() {
    FILE *f;
    f = fopen("/home/n0wee/Coding/labs/2sem/CP6/BD.bin", "wb");
    char male_surnames[][MAXCHAR] = {"Fadeev", "Jilin", "Mamontov", "Ignatyev", "Subotin", "Gorohov", "Kirilov", "Sokolov", "Basharov", "Makarov", "Ivanov"};
    char female_surnames[][MAXCHAR] = {"Fadeeva", "Jilina", "Mamontova", "Ignatyeva", "Subotina", "Gorohova", "Kirilova", "Sokolova", "Basharova", "Makarova", "Ivanova"};
    char initials[][MAXCHAR] = {"DV", "MD", "PV", "ES", "MS", "DG", "KA", "VV", "DS", "MM", "TO"};
    char group[][MAXCHAR] = {"M103", "M108", "M105"};
    char exam[][MAXCHAR] = {"Math", "Rus", "History", "OOP", "Python", "Java"};
    
    srand(time(NULL));
    
    for(int i = 0; i < 11; i++) {
        Student *s = malloc(sizeof(Student));
        int is_male = rand() % 2;
        if (is_male) {
            strcpy(s->surname, male_surnames[rand()%11]);
            strcpy(s->sex, "M");
        } else {
            strcpy(s->surname, female_surnames[rand()%11]);
            strcpy(s->sex, "Ж");
        }
        strcpy(s->initials, initials[rand()%11]);
        strcpy(s->group, group[rand()%3]);
        int count = rand()%4+1;
        s->tests = malloc(count * sizeof(test *));
        for(int j = 0; j < count; j++) {
            test *t = malloc(sizeof(test));
            strcpy(t->name, exam[rand()%MAX_EXAMS]);
            t->score = rand()%3 + 3;
            s->tests[j] = t;
        }
        s->count = count;
        add_student(s, f);
    }
    
    fclose(f);
    return 0;
}
