// A164 · Decimal para binário: a pilha inverte a ordem

#include <stdio.h>
#include "pilha.h"

int main(void) {
    Pilha *restos = pilha_cria();
    if (restos == NULL) {
        return 1;
    }

    int n = 13;
    printf("%d em binário: ", n);
    // os restos da divisão por 2 saem do bit menos significativo para o mais
    // significativo: 1, 0, 1, 1. A pilha devolve na ordem certa: 1, 1, 0, 1.
    while (n > 0) {
        pilha_empilha(restos, n % 2);
        n = n / 2;
    }

    int bit;
    while (pilha_desempilha(restos, &bit)) { // false quando a pilha esvazia
        printf("%d", bit);
    }
    printf("\n");

    pilha_libera(restos);
    return 0;
}
// Saída:
// 13 em binário: 1101
