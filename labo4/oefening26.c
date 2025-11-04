/*
 *  Gebruik schuivende pointer
 *  char *s =/= char s[]
 */
#include <stdio.h>

void my_toupper(char *);

int main() {
    char s[] = "snEEuwwITJE<3!!";

    my_toupper(s);

    printf("%s\n", s);

    char woord[31];
    scanf("%30s", woord);

    my_toupper(woord);

    printf("%s\n", woord);

    return 0;
}

void my_toupper(char *s) {
    if (*s >= 'a' && *s <= 'z') {
        *s = *s - 32; // *s - 'a' + 'A'
    }
    s++;
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = *s + 32;
        }
        s++;
    }
}