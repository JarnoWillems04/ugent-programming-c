#include <stdio.h>

void schrijf_even_posities(char t[], int l );
void schrijf_even_posities_FOUT(char t[], int l );

int main () {
    char letters [] = {'p','o','r','e','o','i','f','o','i','e','c','i','i',':','a','-','t','('};

    // printf("De lengte van de array is %lu", sizeof(letters));
    //
    // for (int i = 0; i < sizeof(letters); i += 2) {
    //     printf("%c", letters[i]);
    // }

    schrijf_even_posities(letters, sizeof(letters)/sizeof(letters[0])); // of sizeof(letters)/sizeof(char)

    return 0;
}

void schrijf_even_posities(char t[], int l ) {
    for (int i = 0; i < l; i += 2) {
        printf("%c", t[i]);
    }
}

void schrijf_even_posities_FOUT(char t[], int l ) {
    for (int i = 0; i < sizeof(t); i += 2) {
        printf("%c", t[i]);
    }
}