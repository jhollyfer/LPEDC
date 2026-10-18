// A290 · A árvore 2-3 escondida na rubro-negra

#include <stdio.h>
#include "rubronegra.h"

// Cole cada nó vermelho no pai: os dois viram um nó de 2 chaves (um "3-nó",
// com 3 filhos). O resultado é uma árvore 2-3, com todas as folhas no mesmo
// nível. Esta função mostra os nós 2-3 que estão no nível alvo.
void nivel_23(const NoRN *h, int alvo) {
    if (h == NULL) {
        return;
    }
    const NoRN *e = h->esq;
    bool tres = e != NULL && e->vermelho; // h + filho vermelho = 3-nó
    if (alvo == 0) {
        if (tres) {
            printf(" [%d %d]", e->chave, h->chave);
        } else {
            printf(" [%d]", h->chave);
        }
        return;
    }
    if (tres) { // os 3 filhos do 3-nó
        nivel_23(e->esq, alvo - 1);
        nivel_23(e->dir, alvo - 1);
    } else {
        nivel_23(h->esq, alvo - 1);
    }
    nivel_23(h->dir, alvo - 1);
}

int main(void) {
    int chaves[] = {50, 20, 80, 10, 30, 60, 90, 40, 70, 25};
    NoRN *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = rn_insere(raiz, chaves[i]);
    }

    printf("Rubro-negra (pré, * = vermelho):");
    rn_pre_ordem(raiz);
    printf("\nAltura: %d | altura preta: %d\n", rn_altura(raiz), rn_altura_preta(raiz));

    printf("Vista como árvore 2-3:\n");
    for (int d = 0; d < rn_altura_preta(raiz); d++) {
        printf("  nível %d:", d);
        nivel_23(raiz, d);
        printf("\n");
    }

    raiz = rn_libera(raiz);
    return 0;
}
// Saída:
// Rubro-negra (pré, * = vermelho): 50 30 20* 10 25 40 80 70 60* 90
// Altura: 3 | altura preta: 3
// Vista como árvore 2-3:
//   nível 0: [50]
//   nível 1: [20 30] [80]
//   nível 2: [10] [25] [40] [60 70] [90]
