#include <stdio.h>
int main() {
    int macht = 1;
    while (macht < 10000) {
        printf("%d ",macht);
        macht *= 2;
    }
    return 0;
}

/*
    int macht = 1;
    while (macht < 10000) {
        macht *= 2;
        printf("%d ",macht);  // TE LAAT
    }

De volgorde van de derde en de vierde regel moet omgewisseld worden.
Dit is heel eenvoudig te controleren, door volgende tip toe te passen:
De VIER delen van de while-lus zijn:
   DEEL 1       klaarzetten van het 'item' waarop getest wordt
   DEEL 2       while (voorwaarde waaraan item moet voldoen om door te gaan in de lus) {
   DEEL 3           // hier komen alle zaken die wel herhaald moeten worden,
                    // maar niet tot DEEL 4 behoren
   DEEL 4           // opnieuw klaarzetten van het 'item' waarop getest wordt
                    // (dit kan eventueel meerdere regels beslaan)
                }
De JUISTE VOLGORDE om deze vier delen te schrijven is als volgt:
Eerst schrijf je DEEL 2. Uit de opgave blijkt namelijk heel makkelijk hoelang je mag doorgaan
met herhalen, dus volgt er ook snel het 'item' waarop getest wordt.
Dan schrijf je DEEL 1 EN DEEL 4.
  DEEL 1 zet het item klaar (deftige initialisatie);
  DEEL 4 is daar (dikwijls) quasi een kopie van. Je zet DEEL 4 ook meteen ONDERAAN de lus.
Dan schrijf je DEEL 3. Alles wat moet herhaald worden, maar niet tot DEEL 4 behoort,
komt VOOR DEEL 4, tussen de accolades.

De correcte oplossing van deze oefening is dus:
    int macht = 1;
    while (macht < 10000) {
        printf("%d ",macht);
        macht *= 2;
    }
*/