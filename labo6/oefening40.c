#include <stdio.h>
#include <stdlib.h>
#include <time.h>

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
void verwijder_knoop(knoop *** lst);
knoop * merge(knoop ** lst1, knoop ** lst2);

int main() {
    srand(time(NULL));
    knoop *m = maak_gesorteerde_lijst_automatisch(10,1000);
    knoop *n = maak_gesorteerde_lijst_automatisch(5,1000);
    printf("\nLIJST m:\n");
    print_lijst(m); // output: 10 geordende getallen + X
    printf("\nLIJST n:\n");
    print_lijst(n); // output: 5 geordende getallen + X

    printf("\nDeze worden gemerged. \n\n");
    knoop *mn = merge(&m,&n);

    printf("\nLIJST m:   \n");
    print_lijst(m); // output: X
    printf("\nLIJST n:   \n");
    print_lijst(n); // output: X
    printf("\nRESULTAAT: \n");
    print_lijst(mn); // output: 15 geordende getallen + X
    verwijder_lijst(&mn);
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

void verwijder_dubbels(knoop ** lst) {
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
        verwijder_knoop(&lst);
    }
}

void verwijder_knoop(knoop *** lst) {
    knoop * h = **lst;
    **lst = (**lst)->volgend;
    free(h);
}

knoop * merge(knoop ** lst1, knoop ** lst2) {
    knoop * merged;
    if ((*lst1)->getal < (*lst2)->getal) {
        merged = *lst1;
        *lst1 = (*lst1)->volgend;
    } else {
        merged = *lst2;
        *lst2 = (*lst2)->volgend;
    }
    knoop *prev = merged;
    while (*lst1 != NULL && *lst2 != NULL) {
        if ((*lst1)->getal < (*lst2)->getal) {
            prev->volgend = *lst1;
            *lst1 = (*lst1)->volgend;
            prev = prev->volgend;
        } else {
            prev->volgend = *lst2;
            *lst2 = (*lst2)->volgend;
            prev = prev->volgend;
        }
    }
    if (*lst1 != NULL) {
        prev->volgend = *lst1;
        *lst1 = NULL;
    } else {
        prev->volgend = *lst2;
        *lst2 = NULL;
    }

    return merged;
}