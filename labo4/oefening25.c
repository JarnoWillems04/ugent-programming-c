#include <stdio.h>

int aantal_verschillende_letters(const char *);

int main(){

    char *s = "Dit is een voorbeeld!";
    printf("Vb: %d\n", aantal_verschillende_letters(s));

    char woord[31];
    scanf("%30s", woord);

    printf("Ingelezen: %d\n", aantal_verschillende_letters(woord));


    return 0;
}

int aantal_verschillende_letters(const char *s) {
    int freq[26] = {0};
    int amount = 0;
    while (*s) {
        if (*s >= 'A' && *s <= 'Z') {
            if (freq[*s - 'A'] == 0) {
                amount++;
                freq[*s - 'A']++;
            }
        } else if (*s >= 'a' && *s <= 'z') {
            if (freq[*s - 'a'] == 0) {
                amount++;
                freq[*s - 'a']++;
            }
        }
        s++;
    }
    return amount;
}

// int aantal_verschillende_letters(const char *s) {
//     //we willen de C-string slechts 1 keer overlopen
//     //we gebruiken dus een aanwezigheidstabel om aan te duiden
//     //welke letters al dan niet voorkomen
//     bool freq[26] = {false};
//     while (*s) {
//         if (*s >= 'A' && *s <= 'Z')  //of isupper gebruiken
//             freq[*s-'A'] = true;
//         else if (*s >= 'a' && *s <= 'z') //of islower gebruiken
//             freq[*s-'a'] = true;
//         s++;
//     }
//     int tel = 0;
//     for (int i=0 ; i<26 ; i++)
//         if (freq[i])
//             tel++;
//     return tel;
// }

// int aantal_verschillende_letters(const char *s) {
//     bool freq[26] = {false};
//     int tel = 0;
//     while (*s) {
//         if (isupper(*s) && !freq[*s-'A']) {
//             freq[*s-'A'] = true;
//             tel++;
//         } else if (islower(*s) && !freq[*s-'a']) {
//             freq[*s-'a'] = true;
//             tel++;
//         }
//         s++;
//     }
//     return tel;
// }

/*
 * scanf voor woordt als woord 30 is lengte 31
 *
 *
 */