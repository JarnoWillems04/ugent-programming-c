/* cstring comparen met stringcompare of zo iets argc -- argv ++ */

#include <stdio.h>
#include <string.h>

void my_toupper(char *s);
const char * alfab_kleinste(const char * const *, int);

int main(int argc, char** argv) {
    if (argc > 1) {
        //zet eerst alle namen om
        for (int i=1; i<argc; i++)
            my_toupper(argv[i]);
        const char * kleinste = alfab_kleinste((const char * const *)argv+1, argc-1);
        /* Merk op: sla het eerste element van argv over!
           En doe dat HIER, het is niet de taak van de functie
           alfab_kleinste om het eerste element over te slaan. */
        printf("Dag %s!",kleinste);
    }
    else printf("Dag allemaal!");
    return 0;
}

void my_toupper(char *s) {
    if (*s >= 'a' && *s <= 'z') {
        *s = *s - 32;
    }
    s++;
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            *s = *s + 32;
        }
        s++;
    }
}

//mogelijk test vraag
 const char * alfab_kleinste(const char * const *voornamen, int n) {
     const char *kl = voornamen[0];
     for (int i=1; i<n; i++)
         if (strcmp(kl,voornamen[i]) > 0)
             kl = voornamen[i];
     return kl;
 }