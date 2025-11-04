#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void een();

void twee();

void drie();

void vier();

int main() {
    srand(time(NULL));
    een();
    return 0;
}

// int main() {
//     clock_t start, stop;
//     double tijd;
//
//     start = clock();    // starttijd meten
//     een();
//     stop = clock();     // stoptijd meten
//
//     tijd = (double)(stop - start) / CLOCKS_PER_SEC;
//     printf("\nTotale looptijd: %f seconden\n", tijd);
//
//     return 0;
// }

//1) Het cijfer is niet groot genoeg om in int te passen 0.000051

void een() {
    for (int i = 2; i <= 30; i++) {
        int fac = 1;

        for (int j = 2; j <= i; j++) {
            fac = fac * j;
        }

        printf("%2d! = %d\n", i, fac);
    }
}

//2) Vanaf fac 21 loopt het weer fout --> voor long
// Verder kan (long long, long double)

void twee() {
    for (int i = 2; i <= 30; i++) {
        unsigned long long fac = 1;

        for (int j = 2; j <= i; j++) {
            fac = fac * j;
        }

        printf("%2d! = %lu\n", i, fac);
    }
}

//3)

void drie() {
    // onder + rand() % (boven - onder + 1)
    int n = rand() % 19 + 2; //getal tussen 2 en 20

    long fac = 1;
    for (int i = 2; i <= n; i++) {
        fac *= i;
    }

    printf("%2d! = %lu\n", n, fac);
}

//4)
void vier() {
    int n = 0;

    while (scanf("%d",&n)==0 || n<2 || n>20) {
        while (getchar() != '\n'); // inputbuffer leegmaken
        printf("Foute input!\n");
        printf("Geef een geheel getal uit het interval [2,20] in: ");
    }

    long fac = 1;
    for (int i = 2; i <= n; i++) {
        fac *= i;
    }

    printf("%2d! = %lu\n", n, fac);
}

