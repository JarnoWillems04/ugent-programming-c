/* !!!!!!!!! void pointers (was testvraag) */
#include <stdbool.h>
#include <stdio.h>

int zijn_ints_gelijk(const void *,const void *);
int zijn_strings_gelijk(const void *,const void*);
bool array_bevat_dubbels_na_elkaar(const void * t, int aantal, int grootte ,int (*zijn_gelijk)(const void *,const void *));

int main() {
    int getallen_ja[]   = {1,2,3,4,5,6,7,8,9,10,10,11};
    int getallen_neen[] = {1,2,1,2,1,2,1,2,1,2,3,4,5};
    char* woorden_ja[]  = {"leentje","leerde","lotje","lopen","lopen","langs","de",
                          "lindelaan"};
    char* woorden_neen[] = {"wie","goed","doet","goed","ontmoet"};

    // voor elk van deze vier arrays wordt er opgeroepen:
    // if (array_bevat_dubbels_na_elkaar(getallen_ja, sizeof(getallen_ja)/sizeof(*getallen_ja), sizeof(*getallen_ja), zijn_ints_gelijk ))
    if (array_bevat_dubbels_na_elkaar(woorden_neen, sizeof(woorden_neen)/sizeof(*woorden_neen), sizeof(*woorden_neen), zijn_strings_gelijk ))
        printf("Deze array bevat dubbels na elkaar");
    else
        printf("Deze array bevat geen dubbels na elkaar");

    return 0;
}

int zijn_ints_gelijk(const void * n,const void * m) {
    return *(int *)n == *(int *)m;
}

int zijn_strings_gelijk(const void * s,const void * t) {
    const char * str1 = s;
    const char * str2 = t;
    while (*str1 && *str2) {
        if (*str1 != *str2) {
            return 0;
        }
        str1++;
        str2++;
    }
    return *str1 == *str2;
}

// bool zijn_strings_gelijk(const void *a, const void *b) {
//     const char * const * aa = (const char * const *) a;
//     const char * const * bb = (const char * const *) b;
//     return strcmp(*aa,*bb)==0;
// }


// int array_bevat_dubbels_na_elkaar(const void * t, int aantal, int grootte ,int (*zijn_gelijk)(const void * i, const void * j)) {
//     t += grootte;
//     for (int i = 0; i < aantal; i++) {
//         if (zijn_gelijk(t, t-grootte)) {
//             return 1;
//         }
//         t+=grootte;
//     }
//
//     return 0;
// }

bool array_bevat_dubbels_na_elkaar(const void *t, int aantal, int grootte,
                            int (*zijn_gelijk) (const void *, const void *)) {
    const char *rij = t;
    for (int i=1 ; i<aantal ; i++)
        if (zijn_gelijk(rij + (i-1)*grootte, rij + i*grootte))
            return true;
    return false;
}

