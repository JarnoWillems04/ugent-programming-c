// EXAMEN!!!!!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXLENGTE 4

char * lees();

int main() {
    for (int i=0; i<5; i++) {
        char *tekst = lees();
        printf("Ik las ***%s*** \n",tekst);
        free(tekst);
    }
    return 0;
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
