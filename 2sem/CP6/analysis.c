#include "repository.h"
#include <stdio.h>
#include <string.h>

bool has_failed_course(test **tests, int count) {
    for (int i = 0; i < count; i++) {
        if (tests[i]->score < 4) {
            return true;
        }
    }
    return false;
}

void print_student(Student *s) {
    fprintf(stdout, "+---------------+--------+---+----------+");
    if (s->tests != NULL) {
        for (int i = 0; i < s->count; i++) {
            for (int j = 0; j < strlen(s->tests[i]->name); j++) fprintf(stdout, "-");
            fprintf(stdout, "--+");
        }
    }
    fprintf(stdout, "\n");
    fprintf(stdout, "|%-15s|   %c.%c  | %s |%-10s|", s->surname, s->initials[0], s->initials[1], s->sex, s->group);
    if (s->tests != NULL) {
        for (int i = 0; i < s->count; i++) fprintf(stdout, "%s %d|", s->tests[i]->name, s->tests[i]->score);
    }
    fprintf(stdout, "\n");
    fprintf(stdout, "+---------------+--------+---+----------+");
    if (s->tests != NULL) {
        for (int i = 0; i < s->count; i++) {
            for (int j = 0; j < strlen(s->tests[i]->name); j++) fprintf(stdout, "-");
            fprintf(stdout, "--+");
        }
        fprintf(stdout, "\n");
    }
}

int main(int argc, const char *argv[]) {
    FILE *f;

    f = fopen("/home/n0wee/Coding/labs/2sem/CP6/BD.bin", "rb");
    if (f == NULL) {
        fprintf(stderr, "Error opening file.\n");
        return 1;
    }

    char p[MAXCHAR] = "";
    bool fflag = false;
    for (int i = 1; i < argc; i++) {
        if (strcmp(argv[i], "-f") == 0) {
            fflag = true;
        }
        if (strcmp(argv[i], "-p") == 0) {
            strcpy(p, argv[i + 1]);
            i++;
        }
    }
    Student s;
    int count = 0;
    int read_result;
    while ((read_result = get_student(&s, f)) == 0) {
        if (strcmp(s.sex, "Ж") == 0 && strcmp(s.group, p) == 0) {
            if (!has_failed_course(s.tests, s.count)) {
                count += 1;
                if (fflag) print_student(&s);
            }
        }
    }

    fprintf(stdout, "Количество студенток из группы %s, которые получают стипендию: %d\n", p, count);
    fclose(f);
    return 0;
}
