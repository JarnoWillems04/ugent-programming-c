#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//AANPASSEN --> aanwezigheidstabel (op ex is dat wees effecient)
int main() {
    const int min = 100;
    const int max = 125;

    srand(time(NULL));

    int t[max - min+1] = {0};

    for (int i = 0; i < sizeof(t)/sizeof(t[0]); i ++) {
        int n = min + rand() % (max - min + 1);
        t[n - min] += 1;
        printf("%d\n", n);
    }
    printf("\n");

    for (int i = 0; i < sizeof(t)/sizeof(t[0]); i++) {
        if (t[i] == 0) {
            printf("%d ", min + i);
        }
    }
    printf("\n");

    return 0;
}
