// A350 · O próximo ônibus a partir de agora

#include <stdio.h>
#include "0175-arvpai.h"

// teto: a menor chave >= k (NULL se não existe). Desce da raiz guardando o
// último nó em que virou à esquerda: ele é o candidato.
NoP *teto(NoP *r, int k) {
    NoP *candidato = NULL;
    while (r != NULL) {
        if (r->chave == k) {
            return r;
        }
        if (k < r->chave) {
            candidato = r; // r serve, mas pode haver um menor à esquerda
            r = r->esq;
        } else {
            r = r->dir;
        }
    }
    return candidato;
}

// piso: a maior chave <= k (o espelho)
NoP *piso(NoP *r, int k) {
    NoP *candidato = NULL;
    while (r != NULL) {
        if (r->chave == k) {
            return r;
        }
        if (k > r->chave) {
            candidato = r;
            r = r->dir;
        } else {
            r = r->esq;
        }
    }
    return candidato;
}

void hora(const NoP *x) {
    if (x == NULL) {
        printf("   --");
    } else {
        printf("%2dh%02d", x->chave / 100, x->chave % 100);
    }
}

int main(void) {
    int saidas[] = {800, 615, 1030, 700, 650, 920, 1200, 730};
    NoP *raiz = NULL;
    for (int i = 0; i < 8; i++) {
        raiz = ap_insere(raiz, saidas[i]);
    }
    int agora[] = {600, 731, 920, 1100, 1300};
    for (int i = 0; i < 5; i++) {
        printf("Cheguei às %2dh%02d | último que saiu: ", agora[i] / 100, agora[i] % 100);
        hora(piso(raiz, agora[i]));
        printf(" | próximo: ");
        hora(teto(raiz, agora[i]));
        printf("\n");
    }
    raiz = ap_libera(raiz);
    return 0;
}
// Saída:
// Cheguei às  6h00 | último que saiu:    -- | próximo:  6h15
// Cheguei às  7h31 | último que saiu:  7h30 | próximo:  8h00
// Cheguei às  9h20 | último que saiu:  9h20 | próximo:  9h20
// Cheguei às 11h00 | último que saiu: 10h30 | próximo: 12h00
// Cheguei às 13h00 | último que saiu: 12h00 | próximo:    --
