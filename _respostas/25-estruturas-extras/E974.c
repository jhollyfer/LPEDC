// 0163 · Skip list
// Exercício E974 · ★☆☆

#include <stdio.h>
#include "skip.h"

void faixa(const Skip *s, int a, int b) {
    const NoSkip *x = &s->cabeca;
    for (int k = s->andares - 1; k >= 0; k--) { // chega no último nó < a
        while (x->prox[k] != NULL && x->prox[k]->chave < a) {
            x = x->prox[k];
        }
    }
    int achou = 0;
    for (const NoSkip *p = x->prox[0]; p != NULL && p->chave <= b; p = p->prox[0]) {
        printf(" %d", p->chave);
        achou++;
    }
    if (achou == 0) {
        printf(" nenhuma");
    }
    printf("\n");
}

int main(void) {
    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3};
    Skip *linha = skip_cria(0);
    for (int i = 0; i < 8; i++) {
        skip_insere_andares(linha, km[i], andares[i]);
    }

    int consultas[][2] = {{15, 45}, {41, 46}, {50, 99}};
    for (int i = 0; i < 3; i++) {
        printf("Paradas entre km %d e km %d:", consultas[i][0], consultas[i][1]);
        faixa(linha, consultas[i][0], consultas[i][1]);
    }

    skip_libera(linha);
    return 0;
}
