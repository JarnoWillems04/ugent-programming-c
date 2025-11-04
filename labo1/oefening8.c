#include <stdio.h>

int main() {
    int amount = 0;
    int input;
    int i = 0;

    while ( i < 5 && scanf("%d", &input) == 1 && input >= 0) {
        i++;
        amount += input;
        printf("Input: %d Amount: %d\n", input, amount);
    }

    printf("Gehele getallen gegeven: %d\n", i);
    printf("Getallen opgeteld samen: %d", amount);

    return 0;
}