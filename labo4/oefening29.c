/* !!!!!!!!! void pointers */
#include <stdio.h>

void schrijf_array(const void *t, int aantal, int grootte, char tussenteken, void (*schrijf)(const void *));
void schrijf_int(const void *);
void schrijf_string(const void *);
void schrijf_double(const void *);

int main() {
    int leeftijden[] = {21, 30, 18, 14, 22, 19};
    char * namen[] = {"Evi", "Jaro", "Timen", "Youri", "Ashaf", "Jennifer"};
    double scores[] = {0.5, 1.6, 8.2, -2.4};

    schrijf_array(leeftijden, sizeof(leeftijden)/sizeof(*leeftijden), sizeof(*leeftijden), ',',  schrijf_int);
    printf("\n");
    schrijf_array(namen, sizeof(namen)/sizeof(*namen), sizeof(*namen), '!',  schrijf_string);
    printf("\n");
    schrijf_array(scores, sizeof(scores)/sizeof(*scores), sizeof(*scores), '~',  schrijf_double);
    printf("\n");

    return 0;
}

// void schrijf_array(const void *t, int aantal, int grootte, char tussenteken, void (*schrijf)(const void *)) {
//     schrijf(t);
//     t += grootte;
//     for (int i = 1; i < aantal; i++ ) {
//         printf("%c", tussenteken);
//         schrijf(t);
//         t += grootte;
//     }
// }

void schrijf_array(const void *t, int aantal, int grootte, char tussenteken,
                   void (*schrijf)(const void*)) {
    const char* hulpptr = (const char*) t;
    schrijf(hulpptr);
    for (int i=1; i < aantal; i++) {
        printf("%c",tussenteken);
        hulpptr += grootte;
        schrijf(hulpptr);
    }
    printf("\n");
}

void schrijf_int(const void * i) {
    printf("%d", *(int *)i);
}

void schrijf_string(const void * i) {
    printf("%s", *(char * *)i);
}

void schrijf_double(const void * i) {
    printf("%lf", *(const double *)i);
}


