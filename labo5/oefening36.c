//TEST vraag geweest + ex

#include <stddef.h>
#include <stdio.h>

void plaats_ptr_op_string(const char * const * * p,char c);

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

    const char * const * ptr = (const char * const *) strings;

    plaats_ptr_op_string(&ptr, 'x');

    if (ptr != NULL) {
        printf("%s", *ptr);
    } else {
        printf("Is null pointer");
    }

    return 0;
}

void plaats_ptr_op_string(const char * const * * p, const char c) {
    while (**p && ***p != c) {
        (*p)++;
    }
    if (**p == 0) { // wel nodig want wijst anders gewoon naar einde van die array maar dit is eigenlijk een pointer naar NULL
        *p = 0;
    }
}