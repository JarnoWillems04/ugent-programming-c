/*
op het scherm verschijnt er

0 11 20 62 40 50
11 62 62

Let op voor de lijn
    (*ppt)++;   // *ppt is een pointer - die wordt een plaats naar rechts opgeschoven

Oplossing van de bijvraag:
In de eerste en laatste for-lus kan je de bovengrens 3 vervangen door
sizeof(pt)/sizeof(int*) of sizeof(pt)/sizeof(pt[0]).
In de tweede for-lus kan je de bovengrens 6 vervangen door
sizeof(t)/sizeof(int) of sizeof(t)/sizeof(t[0]).
*/


#include <stdio.h>
int main() {
    int t[6] = {0,10,20,30,40,50};
    int * pt[3];

    for (int i=0; i<sizeof(pt)/sizeof(pt[0]); i++) {
        pt[i] = &t[2*i];
    }

    pt[1]++;
    pt[2] = pt[1];
    *pt[1] += 1;
    *pt[2] *= 2;

    int **ppt = &pt[0];
    (*ppt)++;
    **ppt += 1;

    for (int i=0; i<sizeof(t)/sizeof(t[0]); i++) {
        printf("%d ",t[i]);
    }
    printf("\n");
    for (int i=0; i<sizeof(pt)/sizeof(pt[0]); i++) {
        printf("%d ",*pt[i]);
    }
    printf("\n");
    return 0;
}