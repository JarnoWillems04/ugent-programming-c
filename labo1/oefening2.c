#include <stdio.h>

int main() {
    for (int i = 0; i <= 64; i++) {
        printf("%4o %4d %4x\n", i, i, i);
    }

    return 0;
}
