// 0163 · Skip list
// Exercício E976 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include "skip.h"

void remove_parada(Skip *s, int chave) {
    NoSkip *antes[SKIP_MAX];
    NoSkip *x = &s->cabeca;
    for (int k = SKIP_MAX - 1; k >= 0; k--) {
        while (x->prox[k] != NULL && x->prox[k]->chave < chave) {
            x = x->prox[k];
        }
        antes[k] = x;
    }
    x = x->prox[0];
    if (x == NULL || x->chave != chave) {
        return;
    }
    for (int k = 0; k < x->andares; k++) { // tira o nó de TODOS os andares dele
        antes[k]->prox[k] = x->prox[k];
    }
    free(x);
    s->n--;
}

void procura(const Skip *s, int km) {
    printf("km %d: %s\n", km, skip_busca(s, km, NULL) ? "tem parada" : "não tem parada");
}

int main(void) {
    int km[] = {5, 12, 18, 23, 31, 40, 47, 56};
    int andares[] = {1, 2, 1, 3, 1, 2, 1, 3};
    Skip *linha = skip_cria(0);
    for (int i = 0; i < 8; i++) {
        skip_insere_andares(linha, km[i], andares[i]);
    }

    remove_parada(linha, 23);
    procura(linha, 47);
    procura(linha, 23);
    skip_mostra(linha);

    skip_libera(linha);
    return 0;
}
