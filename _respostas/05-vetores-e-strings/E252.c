// 0042 · Lendo strings
// Exercício E252 · ★★★
//
// Resposta: o 1º fgets lê "abaca" (encheu os 5); o 2º lê "xi\n" (achou o
// Enter); o 3º lê "uva\n"; o 4º devolve NULL. Saída:
//   [abaca][xi
//   ][uva
//   ]
//   3 leituras

#include <stdio.h>

int main(void) {
    char s[6];
    int leituras = 0;

    while (fgets(s, sizeof(s), stdin) != NULL) {
        printf("[%s]", s);
        leituras++;
    }
    printf("\n%d leituras\n", leituras);
    return 0;
}
