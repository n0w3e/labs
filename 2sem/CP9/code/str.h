// File: str.h

#ifndef STR_H
#define STR_H

#define MAX_KEY_LENGTH 32
#define MAX_TEXT_LENGTH 256

typedef struct {
    char key[MAX_KEY_LENGTH];
    char text[MAX_TEXT_LENGTH];
    int value;
} Record;

#endif // STR_H
