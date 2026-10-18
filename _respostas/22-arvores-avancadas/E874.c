// 0146 · Árvore B
// Exercício E874 · ★★☆

#include <stdio.h>
#include "arvoreb.h"

// mostra as chaves de [a, b] em ordem; *visitados conta os nós lidos
void intervalo(const NoB *r, int a, int b, int *visitados) {
    (*visitados)++;
    for (int i = 0; i < r->n; i++) {
        // a subárvore à esquerda da chave i só tem chaves < chave[i]
        if (!r->folha && a < r->chave[i]) {
            intervalo(r->filho[i], a, b, visitados);
        }
        if (r->chave[i] >= a && r->chave[i] <= b) {
            printf(" %d", r->chave[i]);
        }
        if (r->chave[i] > b) {
            return; // daqui para a direita, tudo é maior que b
        }
    }
    if (!r->folha) {
        intervalo(r->filho[r->n], a, b, visitados);
    }
}

int main(void) {
    int notas[] = {512, 87, 340, 905, 23, 678, 150, 401, 799, 266, 33, 960, 610, 445, 118};
    NoB *r = NULL;
    for (int i = 0; i < 15; i++) {
        r = ab_insere(r, notas[i]);
    }
    int faixas[][2] = {{300, 700}, {100, 160}, {970, 999}};
    for (int k = 0; k < 3; k++) {
        int visitados = 0;
        printf("notas de %d a %d:", faixas[k][0], faixas[k][1]);
        intervalo(r, faixas[k][0], faixas[k][1], &visitados);
        printf(" (%d nós lidos de 9)\n", visitados);
    }
    r = ab_libera(r);
    return 0;
}
