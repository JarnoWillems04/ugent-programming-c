#include <stdio.h>
#include <math.h>

int index_van(double[], int, double);

int main(void) {
    double t[] = {18.5, 20.0, 21.3, 19.9, 22.000000001};
    int n = sizeof(t) / sizeof(t[0]);

    double zoekwaarde;

    while (scanf("%lf", &zoekwaarde) != 1) {
        int c;
        while ((c = getchar()) != '\n' && c != EOF);
    }

    int index = index_van(t, n, zoekwaarde);

    printf("De index van %lf is %d", zoekwaarde, index);

    return 0;
}

int index_van(double t[], const int n, double g) {
    for (int i = 0; i < n; i++) {
        if (fabs(t[i] - g) < 1e-9) {
            return i;
        }
    }
    return -1;
}
