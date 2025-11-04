#include <stdio.h>
#include <stdlib.h>

int ggd(int a, int b);
int zijn_onderling_deelbaar(int a, int b);
void print_onderling_deelbaar(int a, int b);

int main() {

    // printf("%d\n", ggd(-6, -8));
    // printf("%d\n", ggd(24, 18));
    // printf("%d\n", ggd(0, -5));
    // printf("%d\n", ggd(6, -35));

    print_onderling_deelbaar(5, 8);

    return 0;
}

int ggd(int a, int b) {
    a = abs(a);
    b = abs(b);
    if (b == 0) {
        return a;
    }
    if (a == 0){
        return b;
    }

    while (a != b) {
        if (a > b) {
            a -= b;
        }
        else {
            b -= a;
        }
    }

    return a;
}

// de niet-recursieve versie van ggd:
/*
int ggd(int a, int b) {
    a = abs(a); b = abs(b);
    while (b) {
        int oud = a;
        a = b;
        b = oud%b;
    }
    return a;
}
*/

int zijn_onderling_deelbaar(int a, int b) {
    if (ggd(a, b) == 1) {
        return 1;
    }
    return 0;
}

void print_onderling_deelbaar(int a, int b) {
    for (int i = a; i <= b; i++) {
        for (int j = i+1; j <= b; j++) {
            if (zijn_onderling_deelbaar(i, j) == 1) {
                printf("%d en %d zijn onderling ondeelbaar\n", i , j);
            }
        }
    }
}


