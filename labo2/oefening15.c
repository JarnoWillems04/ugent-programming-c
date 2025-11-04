#include <stdio.h>
void lees_input(int[]);

void teken_horizontaal(int[]);

void teken_verticaal(int[]);

int maximum(int[]);

int main() {
    int frequenties[26] = {0};
    lees_input(frequenties);
    teken_horizontaal(frequenties);
    teken_verticaal(frequenties);
    return 0;
}

void lees_input(int freq[]) {
    char c;
    while (scanf("%c", &c) == 1 && c != '$') {
        if (c >= 'A' && c <= 'Z') {
            freq[c - 'A']++;
        } else if (c >= 'a' && c <= 'z') {
            freq[c - 'a']++;
        }
    }
}

void teken_horizontaal(int freq[]) {
    for (int i = 'a'; i < 'a' + 26; i++) {
        printf("%c ", i);

        for (int j = 0; j < freq[i - 'a']; j++) {
            printf("*");
        }

        printf("\n");
    }
}

void teken_verticaal(int freq[]) {
    //get max
    int max = maximum(freq);

    for (int i = 0; i < max; i++) {
        for (int j = 'a'; j < 'a' + 26; j++) {
            if (freq[j-'a'] >= max-i) {
                printf("%c", j);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }

}

int maximum(int freq[]) {
    int max = 0;

    for (int i = 0; i < 26; i++) {
        if (freq[i] > max) {
            max = freq[i];
        }
    }

    return max;
}

// ./cmake-build-debug/oefening15 < gandhi.txt