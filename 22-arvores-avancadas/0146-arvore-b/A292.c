// A292 · As notas fiscais em ordem

#include <stdio.h>
#include "arvoreb.h"

// Em ordem num nó de várias chaves: filho 0, chave 0, filho 1, chave 1, ...,
// chave n-1, filho n. Cada chave fica entre as subárvores das menores e das
// maiores que ela, como na BST.
void em_ordem(const NoB *r) {
    for (int i = 0; i < r->n; i++) {
        if (!r->folha) {
            em_ordem(r->filho[i]);
        }
        printf(" %d", r->chave[i]);
    }
    if (!r->folha) {
        em_ordem(r->filho[r->n]); // o último filho, depois da última chave
    }
}

// quantas chaves há em cada nível (nivel conta a partir da raiz)
void conta_por_nivel(const NoB *r, int nivel, int qtd[]) {
    qtd[nivel] += r->n;
    if (!r->folha) {
        for (int i = 0; i <= r->n; i++) {
            conta_por_nivel(r->filho[i], nivel + 1, qtd);
        }
    }
}

int main(void) {
    int notas[] = {512, 87, 340, 905, 23, 678, 150, 401, 799, 266, 33, 960, 610, 445, 118};
    NoB *r = NULL;
    for (int i = 0; i < 15; i++) {
        r = ab_insere(r, notas[i]);
    }

    printf("Por nível:\n");
    ab_mostra(r);
    printf("Em ordem:");
    em_ordem(r);
    printf("\n");

    int qtd[10] = {0};
    conta_por_nivel(r, 0, qtd);
    for (int d = 0; d <= ab_altura(r); d++) {
        printf("chaves no nível %d: %d\n", d, qtd[d]);
    }

    r = ab_libera(r);
    return 0;
}
// Saída:
// Por nível:
//   nível 0: [340]
//   nível 1: [87] [512 678]
//   nível 2: [23 33] [118 150 266] [401 445] [610] [799 905 960]
// Em ordem: 23 33 87 118 150 266 340 401 445 512 610 678 799 905 960
// chaves no nível 0: 1
// chaves no nível 1: 3
// chaves no nível 2: 11
