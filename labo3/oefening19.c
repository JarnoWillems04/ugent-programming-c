#include <stdio.h>

void schrijf_aantal(const char*, int);
void schrijf(const char*, const char*);

int main() {
    char letters[] = {'p','o','r','g','o','e','d','o','i','e','o','k','i',':','a','-','t','('};
    char *p = letters;
    schrijf_aantal(letters+3,4);
    printf("\n");
    schrijf(p+10,p+12);
    return 0;
}

void schrijf_aantal(const char* t, int aantal) {
    for (int i = 0; i < aantal; i++) {
        printf("%c", t[i]);
    }
}

void schrijf(const char* t,const char* u) {
    while (t[0] != u[0]) {
        printf("%c",t[0]);
        t++;
    }
}


