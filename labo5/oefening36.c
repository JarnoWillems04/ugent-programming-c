//TEST vraag geweest + ex

#include <stddef.h>
#include <stdio.h>

void plaats_ptr_op_string(char *** p,char c);

int main() {

    char *strings[] = {
        "Dit",
        "is",
        "een",
        "array",
        "van",
        "cstrings",
        NULL
    };

    char **ptr = strings;

    plaats_ptr_op_string(&ptr, 'p');

    printf("%s", *ptr);

    return 0;
}

void plaats_ptr_op_string(char *** p, const char c) {
    while (*p && ***p != c) {

        (*p)++;
    }
}