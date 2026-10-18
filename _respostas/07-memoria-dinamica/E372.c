// 0062 · Erros de memória
// Exercício E372 · ★★★
//
// gols[4] nunca recebia valor: o malloc entrega lixo (com o ASan, sempre
// 0xbebebebe, que vira -1094795586). O ASan vigia limites e blocos
// liberados, não se o valor foi escrito; o valgrind acompanha byte a byte
// se cada um já recebeu valor e acusa "Conditional jump or move depends on
// uninitialised value(s)". Com calloc, a rodada que não aconteceu vale 0.

#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int rodadas = 5;
    int *gols = calloc(rodadas, sizeof *gols); // tudo começa em 0
    if (gols == NULL) {
        return 1;
    }
    gols[0] = 2;
    gols[1] = 0;
    gols[2] = 3;
    gols[3] = 1;

    int total = 0;
    for (int i = 0; i < rodadas; i++) {
        total += gols[i];
    }
    if (total >= 0) {
        printf("Total: %d gols\n", total);
        printf("Média por rodada: %.1f\n", (double)total / rodadas);
    } else {
        printf("Total negativo? Algo está muito errado: %d\n", total);
    }
    free(gols);
    return 0;
}
// Saída:
// Total: 6 gols
// Média por rodada: 1.2
