#include <ctype.h>
#include <stdio.h>
/*
 * 2 pointers
 */
void wis(char*);
void schrijf(const char* t);

int main() {
    char zin[] = "8\td?a7!+. -)4h&!e9)b*( )j'(e)!4\n8g|'92o!43e5d/.' 2 3g*(e('d22a'(a25n'(";

    wis(zin);

    schrijf(zin);

    char zin2[31];

    printf("\n");

    fgets(zin2, 31, stdin);
    wis(zin2);

    schrijf(zin2);
    return 0;
}

void wis(char * s) {
    char * p = s;
    while (*s) {
        if (islower(*s) || isspace(*s)) {
            *p = *s;
            p++;
        }
        s++;
    }
    *p = '\0'; // *p = 0;
}

void schrijf(const char* t) {
    while (*t) {
        printf("%c",*t);
        t++;
    }
}