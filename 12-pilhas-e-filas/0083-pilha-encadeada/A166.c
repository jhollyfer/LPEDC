// A166 · Sem teto: 100 mil itens na pilha encadeada

#include <stdio.h>
#include "pilha.h"

// A pilha do vetor (0082) recusaria o 101º item. Esta só para quando acabar a
// memória. O código é o mesmo do cliente da 0082: só o pilha.c mudou.
int main(void) {
    Pilha *p = pilha_cria();
    if (p == NULL) {
        return 1;
    }

    int recusados = 0;
    for (int i = 1; i <= 100000; i++) {
        if (!pilha_empilha(p, i)) {
            recusados++;
        }
    }
    printf("Empilhados: %d, recusados: %d\n", pilha_tamanho(p), recusados);

    int topo;
    if (pilha_topo(p, &topo)) {
        printf("No topo: %d\n", topo);
    }

    // pilha_libera percorre os 100 mil nós; sem ela, o AddressSanitizer
    // acusaria 100 mil vazamentos de 16 bytes
    pilha_libera(p);
    return 0;
}
// Saída:
// Empilhados: 100000, recusados: 0
// No topo: 100000
