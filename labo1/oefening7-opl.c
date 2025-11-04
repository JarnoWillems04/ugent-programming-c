/* LET OP! om zo weinig mogelijk zaken te herberekenen, bewaar je telkens de laatst gebruikte term (bvb -x^3/3!)
 *    en leid je daaruit de volgende term af.
 *    Anders zou je veel berekeningen opnieuw doen. Vergelijk:
 *        om x^5/5! rechtstreeks uit te rekenen, heb je volgende bewerkingen nodig:
 *                   x*x*x*x*x / (1*2*3*4*5)
 *
 *        om x^5/5! af te leiden uit -x^3/3! (het 'vorige resultaat'),  heb je volgende bewerkingen nodig:
 *            ('vorige resultaat') * (-x*x)/(4*5)
 *
 * Dit verschil vergroot als je verder in de reeksontwikkeling bent. */


// *********************************** versie 1 *********************
// we berekenen de som met de eerste 10 termen
#include <stdio.h>
#include <math.h>
int main() {
    double x = 8.2;
    double term = x;
    double som = x;
    for (int i=2 ; i<20 ; i += 2) {
        term *= -x*x / (i*(i+1));
        som += term;
    }
    printf("sin(%.2lf) =  %.15lf \n",x,som);
    printf("controle     %.15lf \n",sin(x));
    return 0;
}

// *********************************** versie 2 *********************
// we vervangen de for-lus door een while-lus
// (totdat de absolute waarde van de laatste term klein genoeg is,
// termen die kleiner zijn dan 1e-16 zullen quasi geen invloed meer hebben op de som)
#include <stdio.h>
#include <math.h>
int main() {
    const double EPS = 1e-16;
    double x = 8.2;
    double term = x;
    double som = term;
    int i=2;
    while (fabs(term)>EPS) {
        term *= -x*x / (i*(i+1));
        som += term;
        i +=2;
    }
    printf("sin(%.2lf) =  %.15lf \n",x,som);
    printf("controle     %.15lf \n",sin(x));
    return 0;
}

// *********************************** versie 3 *********************
// we genereren een random getal met 3 beduidende cijfers uit het interval [-3.200,3.200[
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
int main() {
    srand(time(NULL));
    double x = (-3200 + rand()%6400)/1000.0;
    double term = x;
    double som = x;
    int i = 2;
    while (fabs(term)>1e-16) {
        term *= -x*x/(i*(i+1));
        som += term;
        i += 2;
    }
    printf("sin(%.3lf) = %.15lf \n",x,som);
    printf("controle    %.15lf \n",sin(x));
    return 0;
}

