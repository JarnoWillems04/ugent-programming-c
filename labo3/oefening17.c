
/*
 * 1) Juist, jp wijst naar 7 (i)
 * 2) Juist, j wordt 7
 * 3) Fout, *ip is een null pointer dus kunt geen ding insteken
 * 4) Juist, ip gaat dus nu naar 7 (i) wijzen
 * 5) Fout, heel dom je kan geen adressen wisselen
 * 6) Warning, lukt maar kan beter dus ip wijst naar i en i wordt 8
 *
 * 7) Juist, tp zal naar t[2] wijzen dus 30
 * 8) Juist, het is een adres - een adres dus kom je een int uit vb 12345690 - 12345678
 * 9) Fout, t is een arraynaam, geen gewone pointervariabele
 *10) Juist, het eerste element wordt ++ gedaan dus 10 -> 11
 *11) Juist, j wordt 30 en pas ERNA wordt de inhoud waar tp naar wijst (30) ++ gedaan -> t[2] -> 31
 *12) Juist, i wordt 31 (t[2]) en pas ERNA wordt de pointer verschoven dus tp zal wijzen naar t[3] -> 40
 *
 *13) Juist, v wijst nu naar t[3] en ERNA wordt de pointer verschoven dus tp zal wijzen naar t[4] -> 50
 *14) Fout, het geeft een compileer fout en moet eerst gecast worden (printf("%d", *(int*)v);  // ✅ Correct)
* 15) Fout, je kan niet ++ doen bij een void pointer omdat void geen grootte heeft (sizeof(*v) gaat niet, wat dan wel: v = (int*)v + 1;
*
* 16) Juist, je hoeft via p1 niet te schrijven, het is toegestaan een int* toe te wijzen aan een const int*
*            Je kan de waarde dus niet via p1 aanpassen, maar wel nog via ip.
* 17) Fout, je kan const niet minder strict maken
* 18) Fout, p1 wijst naar een int die "const" wordt beschouwd
* 19) Warning, het wordt best gecast naar een double, (maar nog altijd niet veilig)
* 20) Warning, dp zal wijzen naar t[3], maar nog altijd warning
*
* 21) Juist, jp zal wijzen naar waar p2 wijst (i) --> (er gebeurt eig niks)
* 22) Fout, aangezien p2 een const pointer is naar een int mag deze pointer niet wijzigen (waarde wel)
* 23) Juist, de int waat p2 naar wijst mag wijzigen, dit wordt 16 (8+8 of i + i)
*/


// int main() {
//  int i=7, j;
//  double d;
//  int *ip, *jp, *tp;
//  double *dp;
//  void *v;
//  const int *p1;
//  int * const p2 = &i;
//  int t[5] = {10,20,30,40,50};
//
//  /* 1*/ jp = &i;
//  /* 2*/ j = *jp;
//  // /* 3*/ *ip = i;
//  /* 4*/ ip = jp;
//  // /* 5*/ &i = ip;
//  /* 6*/ (*ip)++;
//
//  /* 7*/ tp = t+2;
//  /* 8*/ j = &t[4] - tp;
//  // /* 9*/ t++;
//  /*10*/ (*t)++;
//  /*11*/ j = (*tp)++;
//  /*12*/ i = *tp++;
//
//  /*13*/ v = tp++;
//  // /*14*/ printf("%d", *v);
//  /*15*/ v++;
//
//  /*16*/ p1 = ip;
// }