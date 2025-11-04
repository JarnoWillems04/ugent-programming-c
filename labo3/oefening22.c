#include <stdio.h>
#include <math.h>

int* plaats_van(int *, int, int);
void plaats_ptr_op_getal(const int**, int, int);

void schrijf(const int *t, int aantal) {
    for (int i=0; i<aantal; i++)
        printf("%d ", t[i]);
    printf("\n");
}

int main() {

    int t[] = {18, 20, 21, 19, 22};

    int * p = plaats_van(t, sizeof(t)/sizeof(t[0]), 21);
    if (p == NULL) {
        printf("Het getal is niet gevonden in de array\n");
    }
    else {
        *p *= 2;
        printf("Het getal is gevonden op index %ld\n", (p - t));
    }
    schrijf(t, sizeof(t)/sizeof(t[0]));

    printf("\n--- Test plaats_ptr_op_getal ---\n");

    // Test plaats_ptr_op_getal procedure
    const int *ptr = t;  // Pointer naar begin van array
    plaats_ptr_op_getal(&ptr, sizeof(t)/sizeof(t[0]), 19);

    if (ptr == NULL) {
        printf("Het getal is niet gevonden in de array\n");
    }
    else {
        printf("Het getal is gevonden op index %ld\n", (ptr - t));
    }

    return 0;
}

int* plaats_van(int * t,const int n,int g) {
    for (int i = 0; i < n; i++) {
        if (t[i] == g) {
            return t+i;
        }
    }
    return NULL;
}

void plaats_ptr_op_getal(const int** p, int n, int g) {
    int *hulp = *p;  // Schuivende pointer
    int i = 0;

    while (i < n && *hulp != g) {
        hulp++;
        i++;
    }

    if (i == n) {
        *p = NULL;  // Getal niet gevonden
    }
    else {
        *p = hulp;  // Update de originele pointer
    }
}

/*
void plaats_ptr_op_getal(const int **p, int n, int g) {
// of (als extra beveiliging, zodat p zeker niet verzet wordt):
//void plaats_ptr_op_getal(const int ** const p, int n, int g) {
    int i = 0;
    while (i<n && g!=**p) {
        (*p)++;
        i++;
    }
    if (i==n)
        *p = NULL;
}
 */