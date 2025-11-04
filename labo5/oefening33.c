/*
 *Als param een struct is: NIET KOPIEREN
 * => gebruik pointer naar struct
 * Struct in struct
 *
 * c->mp.y = (*c).mp.y
 */

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double x, y;
} punt;

double afstand_euclidisch(const punt *, const punt *);

double afstand_manhatten(const punt *, const punt *);

double afstand_chebyshev(const punt *, const punt *);

double bepaal_max_afstand(const punt *, int, double (const punt *, const punt *));

int main() {
    int aantal;
    printf("Hoeveel punten \n");
    scanf("%d", &aantal);

    punt punten[aantal];

    for (int i = 0; i < aantal; i++) {
        printf("Geef het x coo van punt %d\n", i + 1);
        scanf("%lf", &punten[i].x);
        printf("Geef het y coo van punt %d\n", i + 1);
        scanf("%lf", &punten[i].y);
    }

    printf("Euclidisch: %lf\n", bepaal_max_afstand(punten, aantal, afstand_euclidisch));
    printf("Manhatten: %lf\n", bepaal_max_afstand(punten, aantal, afstand_manhatten));
    printf("Chebyshev: %lf\n", bepaal_max_afstand(punten, aantal, afstand_chebyshev));

    return 0;
}

double afstand_euclidisch(const punt *a, const punt *b) {
    return sqrt(pow(b->x - a->x, 2) + pow(b->y - a->y, 2));
}

double afstand_manhatten(const punt *a, const punt *b) {
    return fabs(b->x - a->x) + fabs(b->y - a->y);
}

double afstand_chebyshev(const punt *a, const punt *b) {
    return fmax(fabs(b->x - a->x), fabs(b->y - a->y));
}

double bepaal_max_afstand(const punt *punten, int aantal, double afstand_f(const punt *, const punt *)) {
    double max = 0;

    for (int i = 0; i < aantal; i++) {
        for (int j = i + 1; j < aantal; j++) {
            double afstand = afstand_f(&punten[i], &punten[j]);
            if (max < afstand) {
                max = afstand;
            }
        }
    }

    return max;
}
