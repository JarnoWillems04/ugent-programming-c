/*
 * Er gaat niks gebeuren met deze variabelen aangezien ze in het porces worden gewisseld maar dit heeft geen effect
 * op de rest van de main scope. (Er moest dus met pointers :) )
 *
 */

#include <stdio.h>

void wissel(int * a, int * b) {
    //eventueel met een extra const, ter beveiliging,
    //zodat de pointers a en b niet (per ongeluk) verplaatst worden
    //void wissel(int * const a, int * const b) {
    printf("  Bij start van de wisselprocedure hebben we a=%d en b=%d.\n",a,b);
    int hulp = *a;
    *a = *b;
    *b = hulp;
    printf("  Op het einde van de wisselprocedure hebben we a=%d en b=%d.\n",a,b);
}

int main() {
    int x = 5;
    int y = 10;
    printf("Eerst hebben we x=%d en y=%d.\n",x,y);
    wissel(&x,&y);
    printf("Na de wissel hebben we x=%d en y=%d.\n",x,y);
    return 0;
}