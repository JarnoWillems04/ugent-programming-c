//HERHALING OEF GOED VOOR EX

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int waarde;
    int aantal_delers;
    int * delers;
} deeltal;

void schrijf_ints(const int * t,int n);
void schrijf_deeltal(const deeltal * d);
void lees_deeltal(deeltal * g);
int * delers_van(int x, int aantal);
int aantal_delers_van(int x);
void lees_deeltallen(deeltal t[], int aantal);
void schrijf_deeltallen(deeltal t[], int aantal);
deeltal * zoek(int waarde, deeltal t[], int aantal);

int main() {
    printf("Hoeveen deeltallen wil je maken?");
    int aantal;
    scanf("%d", &aantal);
    deeltal t[aantal];
    lees_deeltallen(t,aantal);
    schrijf_deeltallen(t, aantal);

    printf("----------------\n");

    deeltal * dt = zoek(6, t, aantal);
    if (dt == NULL) {
        printf("Getal niet gevonden");
    }
    else {
        schrijf_deeltal(dt);
    }

    for (int i = 0; i < aantal; i++) {
        free(t[i].delers);
    }

    return 0;
}

void schrijf_ints(const int * t, int n) {
    for (int i = 0; i < n - 1; i++) {
        printf("%d-", t[i]);
    }
    printf("%d\n", t[n-1]);
}

void schrijf_deeltal(const deeltal * d) {
    printf("%d\t", d->waarde);
    schrijf_ints(d->delers, d->aantal_delers);
}

int *delers_van(int x, int aantal) {
    int *delers = malloc(aantal * sizeof(int));

    int j = 0;
    for (int i = 1; i <= x && j < aantal; i++) {
        if (x % i == 0) {
            delers[j++] = i;
        }
    }

    return delers;
}

int aantal_delers_van(int x) {
    int aantal = 0;

    for (int i = 1; i <= x/2; i++) {
        if (x % i == 0) {
            aantal++;
        }
    }

    return aantal;
}

void lees_deeltal(deeltal * g) {
    int waarde;
    scanf("%d", &waarde);
    int aantal_delers = aantal_delers_van(waarde);
    int * t = delers_van(waarde, aantal_delers);
    g->waarde = waarde;
    g->aantal_delers = aantal_delers;
    g->delers = t;
}

void lees_deeltallen(deeltal t[], int aantal) {
    for (int i = 0; i < aantal; i++) {
        lees_deeltal(&t[i]);
    }
}

void schrijf_deeltallen(deeltal t[], int aantal) {
    for (int i = 0; i < aantal; i++) {
        schrijf_deeltal(&t[i]);
    }
}

deeltal * zoek(int waarde, deeltal t[], int aantal) {

    for (int i = 0; i < aantal; i++) {
        if (t[i].waarde == waarde) {
            return &t[i];
        }
    }
    return NULL;
}