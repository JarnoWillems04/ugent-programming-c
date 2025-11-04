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
    char buffer[MAXLENGTE + 1];  // ruimte voor '\n'

    fgets(buffer, sizeof(buffer), stdin);

    int len = strlen(buffer);

    if (buffer[len - 1] == '\n') {
        buffer[len -1] = 0;
        len --;
    }
    else {
        while (getchar() != '\n');
    }

    // maak nieuwe string van juiste lengte
    char *resultaat = malloc(len + 1); // malloc( len + 1 * sizeof(char) )
    strcpy(resultaat, buffer);

    return resultaat;
}
