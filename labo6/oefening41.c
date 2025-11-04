
#include <stdio.h>
#include <stdlib.h>
typedef struct knoop knoop;
struct knoop {
    int getal;
    knoop *volgend;
};

void voeg_getal_toe(int g, knoop **pl);
void print_lijst(const knoop * lst);

int main(void) {
    knoop * lijst = NULL;

    lijst = malloc(sizeof(knoop));
    lijst->getal = 3;
    lijst->volgend = malloc(sizeof(knoop));
    lijst->volgend->getal = 7;
    lijst->volgend->volgend = malloc(sizeof(knoop));
    lijst->volgend->volgend->getal = 12;
    lijst->volgend->volgend->volgend = NULL;

    // voorbeeld-aanroepen
    voeg_getal_toe(8, &lijst);
    printf("8 toegevoegd");
    voeg_getal_toe(2, &lijst);
    voeg_getal_toe(8, &lijst);
    voeg_getal_toe(20, &lijst);

    printf("Lijst na toevoegen van getallen:\n");
    print_lijst(lijst);

    // geheugen vrijmaken
    knoop *h;
    while (lijst != NULL) {
        h = lijst;
        lijst = lijst->volgend;
        free(h);
    }

    return 0;
}

void voeg_getal_toe(int g, knoop **pl) {
    while (*pl != NULL && (*pl)->getal < g) {
        pl = &(*pl)->volgend;
    }

    knoop * n = malloc(sizeof(knoop));
    n->getal = g;
    n->volgend = *pl;
    *pl = n;
}

void print_lijst(const knoop * lst) {
    while (lst) {
        printf("%d-", lst->getal);
        lst = lst->volgend;
    }
    printf("X\n");
}