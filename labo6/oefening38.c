#include <stdio.h>
#include <stdlib.h>

typedef struct knoop knoop;
struct knoop {
    int getal;
    knoop *volgend;
};

void print_lijst(const knoop * lst);
void voeg_vooraan_toe(int getal,knoop ** lst);
void vernietig_lijst(knoop ** lst);

int main() {
    knoop *lst = NULL;
    print_lijst(lst);  // output: X
    voeg_vooraan_toe(7, &lst );
    voeg_vooraan_toe(3, &lst );
    print_lijst( lst ); // output: 3 7 X
    vernietig_lijst( &lst );
    print_lijst( lst ); // output: X
    return 0;
}

void print_lijst(const knoop * lst) {
    while (lst) {
        printf("%d ", lst->getal);
        lst = lst->volgend;
    }
    printf("X\n");
}

void voeg_vooraan_toe(int getal, knoop ** lst) {
    knoop *knp = malloc(sizeof(knoop));
    knp->getal = getal;
    knp->volgend = *lst;
    *lst = knp;
}

void vernietig_lijst(knoop ** lst) {
    while (*lst) {
        knoop *h = *lst;
        *lst = h->volgend;
        free(h);
    }
}
