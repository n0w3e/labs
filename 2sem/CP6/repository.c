#include "repository.h"

int str_write(char *s, FILE *f) {
    if (fwrite(s, sizeof(char), MAXCHAR, f) != MAXCHAR) {
        printf("ERROR");
        return 1;
    }
    return 0;
}

int int_write(int *i, FILE *f) {
    if (fwrite(i, sizeof(int), 1, f) != 1) {
        printf("ERROR");
        return 1;
    }
    return 0;
}

int str_read(char *s, FILE *f) {
    if (fread(s, sizeof(char), MAXCHAR, f) != MAXCHAR) {
        return 1;
    }
    return 0;
}

int int_read(int *i, FILE *f) {
    if (fread(i, sizeof(int), 1, f) != 1) {
        return 1;
    }
    return 0;
}

int add_student(Student *s, FILE *f) {
    int i = 0;
    i += str_write(s->surname, f);
    i += str_write(s->initials, f);
    i += str_write(s->sex, f);
    i += str_write(s->group, f);
    i += int_write(&s->count, f); // Write the count of tests

    for (int j = 0; j < s->count; j++) {
        i += add_test(s->tests[j], f);
    }

    if (i > 0) return 1;
    else return 0;
}

int add_test(test *t, FILE *f) {
    int i = 0;
    i += str_write(t->name, f);
    i += int_write(&t->score, f);
    if (i > 0) return 1;
    else return 0;
}

int get_student(Student *s, FILE *f) {
    int i = 0;
    i += str_read(s->surname, f);
    i += str_read(s->initials, f);
    i += str_read(s->sex, f);
    i += str_read(s->group, f);
    i += int_read(&s->count, f); // Read the count of tests

    s->tests = (test**) malloc(s->count * sizeof(test*));
    if (s->tests == NULL) {
        return 1; // Если не удалось выделить память
    }

    for (int j = 0; j < s->count; j++) {
        s->tests[j] = (test*) malloc(sizeof(test));
        if (s->tests[j] == NULL) {
            for (int k = 0; k < j; k++) {
                free(s->tests[k]);
            }
            free(s->tests);
            return 1; // Если не удалось выделить память
        }
        i += get_test(s->tests[j], f);
    }

    if (i > 0) {
        free_student(s);
        return 1;
    } else {
        return 0;
    }
}

int get_test(test *t, FILE *f) {
    int i = 0;
    i += str_read(t->name, f);
    i += int_read(&t->score, f);
    if (i > 0) return 1;
    else return 0;
}

void add_test_to_student(test *t, Student *s) {
    if (s->tests == NULL) {
        s->tests = (test**) malloc(sizeof(test*));
        s->tests[0] = t;
        s->count = 1;
    } else {
        s->tests = (test**) realloc(s->tests, sizeof(test*) * (s->count + 1));
        s->tests[s->count] = t;
        s->count += 1;
    }
}

void free_test(test *t) {
    if (t != NULL) {
        free(t);
    }
}

void free_student(Student *s) {
    if (s->tests != NULL) {
        for (int i = 0; i < s->count; i++) {
            free_test(s->tests[i]);
        }
        free(s->tests);
    }
}
