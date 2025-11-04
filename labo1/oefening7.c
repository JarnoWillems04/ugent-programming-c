#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

void een();
void twee();
void drie();
double sinus(double x);
double power(double x, int n);
double fact(int number);

int main() {
    srand(time(NULL));
    drie();

    return 0;
}

void een() {
    double sinus_result = sinus(0.23);
    double sin_result = sin(0.23);

    printf("0.32 rad:\n");
    printf("Resulaat eigen functie: %lf\n", sinus_result);
    printf("Resulaat ingebouwde functie: %lf\n", sin_result);
    printf("\n8.2 rad:\n");
    printf("Resulaat eigen functie: %lf\n", sinus(8.2));
    printf("Resulaat ingebouwde functie: %lf\n", sin(8.2));
}

void twee() {
    double x = 8.2;
    double sinus = 0;
    int n = 0;
    double term = 1;

    printf("Berekening voor x = 8.2 radialen:\n");
    printf("n\tTerm waarde\t\tCumulatief\n");
    printf("---------------------------------------------------\n");

    while (fabs(term) >= 1e-16) {
        term = (power(-1, n) / fact(2 * n + 1)) * power(x, 2 * n + 1);
        sinus += term;

        printf("%d\t%.10e\t%.10lf\n", n, term, sinus);

        n++;
    }

    printf("\nEindresultaat: %.10lf\n", sinus);
    printf("Ingebouwde sin(8.2): %.10lf\n", sin(8.2));
    printf("Aantal termen nodig: %d\n", n);
}

void drie() {
    // -3.2 + (rand()%6400/1000.0);
    double r = (rand() % 6400 - 3200)  / 1000.0;

    printf("De sinus van %.3lf is %lf", r, sinus(r));
}

double sinus(double x) {
    double sinus = 0;

    for (int n = 0; n < 10; n++) {
        sinus += (power(-1, n)/fact(2 * n +1)) * power(x, 2 * n + 1);
    }

    return sinus;
}

double power(const double x, const int n) {
    double pow = 1;
    for (int i = 0; i < n; i++) {
        pow *= x;
    }
    return pow;
}

double fact(const int number) {
    double fac = 1;
    for (int i = 2; i <= number; i++) {
        fac *= i;
    }
    return fac;
}