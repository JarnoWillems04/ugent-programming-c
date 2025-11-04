#include <stdio.h>
const int AANTAL = 5;

//Vragen
// void vul_array(const int *, const int *, int *, int, int (*)(int,int) );
void vul_array(const int*,const int*, int*,int, int (int, int));

int som(int a, int b) {
    return a+b;
}

int product(int a, int b) {
    return a*b;
}

int verschil(int a, int b) {
    return a-b;
}

void schrijf(const int *t, int aantal) {
    for (int i=0; i<aantal; i++)
        printf("%d ",t[i]);
    printf("\n");
}

int main() {
    int a[AANTAL];
    int b[AANTAL];
    int c[AANTAL];
    for(int i=0; i<AANTAL; i++) {
        a[i] = 10*i;
        b[i] = i;
    }

    vul_array(a,b,c,AANTAL,som);
    schrijf(c,AANTAL); //output: 0 11 22 33 44

    vul_array(a,b,c,AANTAL,product);
    schrijf(c,AANTAL); //output: 0 10 40 90 160

    vul_array(a,b,c,AANTAL,verschil);
    schrijf(c,AANTAL); //output: 0 9 18 27 36
    return 0;
}

void vul_array(const int* a,const int* b, int* c,const int n, int f(int, int)) {
// void vul_array(const int* a,const int* b, int* c,const int n, int (*f)(int, int)) {
    for (int i = 0; i < n; i++) {
        c[i] = f(a[i], b[i]);
    }
}



