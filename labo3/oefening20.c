#include <stdio.h>

void zoek_extremen(const int*, int ,int*, int*);

int main() {
    int min, max;
    int getallen1[] = {5,7,999,6,4,2,3,8,5,-11,5,4,2};
    int getallen2[] = {-5,-2,-888,-3,-9,-4,-1,-7};

    //roep de procedure zoek_extremen aan zodat
    //het mininum en maximum van getallen1 bepaald wordt
    zoek_extremen(getallen1, sizeof(getallen1)/sizeof(getallen1[0]) , &min, &max);
    printf("getallen1: min is %d,  max is %d\n",min,max);

    //roep de procedure zoek_extremen aan zodat
    //het mininum en maximum van getallen2 bepaald wordt
    zoek_extremen(getallen2, sizeof(getallen2)/sizeof(getallen2[0]), &min, &max);
    printf("getallen2: min is %d,  max is %d\n",min,max);
    return 0;
}

void zoek_extremen(const int* t, int aantal, int* min, int* max) {
    *min = t[0];
    *max = t[0];
    // if (aantal <= 1) {
    //     return;
    // }
    for (int i = 0; i < aantal; i++) {
        if (t[i] < *min) {
            *min = t[i];
        }
        else if (t[i] > * max) {
            *max = t[i];
        }
    }
}