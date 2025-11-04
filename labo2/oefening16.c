#include <stdio.h>

void lees_matrix(int(*)[3], int, int);

void print_matrix(int(*)[3], int, int);

void transponeer(int(*)[3], int);

int main() {
    int kol = 3;
    int rij = 3;

    int matrix[rij][kol];

    lees_matrix(matrix, rij, kol);
    print_matrix(matrix, rij, kol);
    transponeer(matrix, rij);
    print_matrix(matrix, rij, kol);

    return 0;
}

void lees_matrix(int (*matrix)[3], int aant_rij, int aant_kol) {
    int input = 0;
    int i = 0;
    while (i < aant_kol * aant_rij && scanf("%d", &input) == 1) {
        matrix[i / aant_kol][i % aant_kol] = input;
        i++;
    }
}

void print_matrix(int (*matrix)[3], int aant_rij, int aant_kol) {
    for (int i = 0; i < aant_rij; i++) {
        for (int j = 0; j < aant_kol; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void transponeer(int (*matrix)[3], int aant_rij) {
    for (int i = 0; i < aant_rij; i++) {
        for (int j = i; j < aant_rij; j++) {
            int n = matrix[i][j];
            matrix[i][j] = matrix[j][i];
            matrix[j][i] = n;
        }
    }
}