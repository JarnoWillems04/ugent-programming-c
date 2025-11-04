
#include <stdio.h>
#include <stdlib.h>
typedef struct knoop knoop;
struct knoop {
    int getal;
    knoop *volgend;
};

void verwijder(int x, knoop ** lst);
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

    printf("Lijst voor verwijderen van getallen:\n");
    print_lijst(lijst);

    printf("Lijst na verwijderen van getal");
    verwijder(12, &lijst);
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

void verwijder(int x, knoop ** lst) {
    while (*lst != NULL && (*lst)->getal != x) {
        lst = &((*lst)->volgend);
    }

    knoop * k = *lst;
    *lst = (*lst)->volgend;
    free(k);
}

void print_lijst(const knoop * lst) {
    while (lst) {
        printf("%d-", lst->getal);
        lst = lst->volgend;
    }
    printf("X\n");
}