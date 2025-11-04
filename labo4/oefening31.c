#include <stdio.h>
void my_toupper(char *s);

int main(int argc, char ** argv) {
    if (argc == 1) {
        printf("Dag allemaal!");
    }
    else {
        for (int i = 1; i < argc; i++) {
            my_toupper(argv[i]);
            printf("Dag %s!\n",argv[i]);
        };
    }

    return 0;
}

void my_toupper(char *s) {
    if (*s >= 'a' && *s <= 'z') {
        *s = *s - 32;
    }
    s++;
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = *s + 32;
        }
        s++;
    }
}