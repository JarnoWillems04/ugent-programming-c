#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int cijfersom(int x);

int main () {
    srand(time(NULL));

    for (int i = 0; i < 10; i++) {
        int random = rand() % 1000;
        int cs = cijfersom(random);
        printf("Cijfersom van: %d: %d\n", random , cs) ;
    }

    return 0;
}

int cijfersom(int x) {
    int som = 0;

    while (x > 0) {
        som += x % 10;
        x /= 10;
    }

    return som;
}