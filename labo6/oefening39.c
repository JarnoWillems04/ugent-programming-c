#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//aantal * ? moet de pointer verschoven worden of niet -> zo ja 2 ** anders *

typedef struct knoop knoop;
struct knoop {
    int getal;
    knoop *volgend;
};

void print_lijst(const knoop * lst);
knoop * maak_gesorteerde_lijst_automatisch(int aantal, int max);
void verwijder_dubbels(knoop ** lst);
void voeg_vooraan_toe(int getal,knoop ** lst);
void verwijder_lijst(knoop ** lst);

int main() {
    srand(time(NULL));
    knoop *l = maak_gesorteerde_lijst_automatisch(10,100);
    print_lijst(l);
    printf("\nnu worden dubbels verwijderd: \n");
    verwijder_dubbels(&l);  // aan te vullen
    printf("\nna verwijderen van dubbels: \n\n");
    print_lijst(l);
    verwijder_lijst(&l);
    return 0;
}

void print_lijst(const knoop * lst) {
    while (lst) {
        printf("%d ", lst->getal);
        lst = lst->volgend;
    }
    printf("X\n");
}

knoop * maak_gesorteerde_lijst_automatisch(int aantal, int max) {
    knoop * lst = NULL;

    int getal = max;

    for (int i = 0; i< aantal; i++) {
        voeg_vooraan_toe(getal, &lst);

        int verschil = rand() % 3;
        getal -= verschil;
        if (getal < 0) {
            getal = 0;
        }
    }
    return lst;
}

void voeg_vooraan_toe(int getal,knoop ** lst) {
    knoop * k = malloc(sizeof(knoop));
    k->getal = getal;
    k->volgend = *lst;
    *lst = k;
}

void verwijder_dubbels(knoop ** lst) {//maken met 1 *
    if (*lst == NULL) return;

    knoop *k = *lst;

    while (k->volgend != NULL) {
        if (k->getal == k->volgend->getal) {
            printf("%d ", k->getal);
            knoop * h = k->volgend;
            k->volgend = h->volgend;
            free(h);
        }
        else {
            k = k->volgend;
        }
    }
}

void verwijder_lijst(knoop ** lst) {
    while (*lst) {
        knoop * h = *lst;
        *lst = (*lst)->volgend;
        free(h);
    }
}