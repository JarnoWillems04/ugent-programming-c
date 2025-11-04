// EXAMEN!!!!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTE 4

char * lees();
char ** lees_meerdere(int);

int main() {
    int n = 5;
    char **lijnen = lees_meerdere(n);

    printf("\n--- Ingelezen tekst ---\n");
    for (int i = 0; lijnen[i] != NULL; i++) {
        printf("%s\n", lijnen[i]);
    }

    for (int i = 0; lijnen[i] != NULL; i++) {
        free(lijnen[i]);
    }
    free(lijnen);

    return 0;
}

char ** lees_meerdere(int n) {
    char ** array = malloc((n+1)  * sizeof(char *));

    for (int i = 0; i < n; i++) {
        printf("Geef lijn %d: ", i+1);
        array[i] = lees();
    }

    array[n] = NULL;

    return array;
}

char *lees() {
    char buffer[MAXLENGTE + 1];  // ruimte voor '\n' en '\0'

    fgets(buffer, sizeof(buffer), stdin);

    int len = strlen(buffer);

    if (buffer[len - 1] == '\n') {
        buffer[len -1] = 0;
        len --;
    }
    else {
        int ch;
        while ((ch = getchar()) != '\n' && ch != EOF);
    }

    // maak nieuwe string van juiste lengte
    char *resultaat = malloc(len + 1);
    strcpy(resultaat, buffer);

    return resultaat;
}
