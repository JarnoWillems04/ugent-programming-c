#include <stdio.h>

void pivoteer (char * begin, char * einde, char * p);
void schrijf( char * t1, char * t2 );

int main() {
    char tekst[] = {'b','d','?','z','g','o','e','z','e','b',
                    ' ','d','i','g','!','h','o','s','v'};
    pivoteer(tekst+7,tekst+12,tekst+9);
    schrijf(tekst+4,tekst+15);
    return 0;
}

//z e -b- ' ' d i
void pivoteer (char * begin, char * einde, char * p){
    int i = 1;
    while (begin <= (p-i) && einde >= (p+i)){
        char hulp = *(p-i);
        *(p-i) = *(p+i);
        *(p+i) = hulp;
        i++;
    }
}

void schrijf(char * t1, char * t2){
    while (t1 != t2){
        printf("%c", *t1);
        t1++;
    }
}