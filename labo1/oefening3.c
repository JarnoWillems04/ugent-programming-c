#include <stdio.h>
int main() {
    for(int i=10; i>0; i--) {
        if(i==10) {
            printf("Hello world!\n");
        }
        printf("%d ",i);
        if(i==1) {
            printf("\nSTART");
        }
    }
    return 0;
}

//Slecht omdat??
/* Er wordt in elke loop gecked of i == 10 of 1
 * Maakt het programma trager
 * Mag enkel in specifieke gevallen, (maar als if aan begin en einde zit beter niet)
 */

/*
Testen op de teller binnen een for-lus is NOT DONE, tenzij in het onwaarschijnlijke geval
dat de test een ingewikkelde berekening op die teller vraagt.
Maar testen of je aan het begin dan wel aan het einde van de lus zit, DOE JE NIET.

Ga maar eens na wat deze overbodige testen voor de efficientie van je programma betekenen,
als we niet van 10 tot 1 maar van 1000000000000000000000000000 tot 1 laten aftellen!
*/
