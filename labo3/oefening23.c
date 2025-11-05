#include <stdio.h>
#include <stdlib.h>

void pivoteer(char*, char*, char*);
void schrijf(const char*,const char*);

int main() {
    char tekst[] = {'b','d','?','z','g','o','e','z','e','b',
                    ' ','d','i','g','!','h','o','s','v'};
    pivoteer(tekst+7,tekst+12,tekst+9);
    schrijf(tekst+4,tekst+15);
    return 0;
}

// 7 8 9 10 11 12
void pivoteer(char* begin, char* einde, char* pivot) {
    einde--;
    while (begin != pivot && einde != pivot) {
        char hulp = *begin;
        *begin = *einde;
        *einde = hulp;

        begin++;
        einde--;
    }
}

/*
*void pivoteer(char *begin, char *einde, char *pivot) {
    char *voor = pivot-1;
    char *na = pivot+1;
    while (voor>=begin && na<einde) {
        char h = *voor;
        *voor = *na;
        *na = h;
        voor--;
        na++;
    }
}
 */

// void pivoteer (char * begin, char * einde, char * p){
//     int i = 1;
//     while (begin <= (p-i) && einde >= (p+i)){
//         char hulp = *(p-i);
//         *(p-i) = *(p+i);
//         *(p+i) = hulp;
//         i++;
//     }
// }

void schrijf(const char* t,const char* u) {
    while (t != u) {
        printf("%c",t[0]);
        t++;
    }
}


