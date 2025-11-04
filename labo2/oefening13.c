
#include <stdio.h>

void schuif_links(char t[], int n);
void schrijf(char[], int);

int main() {

    char rij[] = {'s','a','p','a','p','p','e','l'};
    int size = sizeof(rij)/sizeof(rij[0]);
    schuif_links(rij, size);
    schrijf(rij, size);

    schuif_links(rij, size);
    schrijf(rij, size);

    schuif_links(rij, size);
    schrijf(rij, size);

    return 0;
}

void schrijf(char t[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%c", t[i]);
    }

    printf("\n");
}


void schuif_links(char t[],int n) {
    char first = t[0];
    for (int i = 0; i < n-1; i++) {
        t[i] = t[i + 1];
    }
    t[n-1] = first;
}