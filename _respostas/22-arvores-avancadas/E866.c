// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E866 · ★☆☆

#include <stdio.h>
#include "rubronegra.h"

// quantos nós a busca visita até achar a chave ou cair num NULL
int passos(const NoRN *r, int chave) {
    int n = 0;
    while (r != NULL) {
        n++;
        if (chave == r->chave) {
            break;
        }
        r = chave < r->chave ? r->esq : r->dir;
    }
    return n;
}

int main(void) {
    NoRN *raiz = NULL;
    for (int c = 1; c <= 100; c++) {
        raiz = rn_insere(raiz, c);
    }
    int testes[] = {1, 50, 64, 100, 101};
    for (int i = 0; i < 5; i++) {
        printf("busca %3d: %s (passos: %d)\n", testes[i],
               rn_busca(raiz, testes[i]) ? "achou" : "não achou", passos(raiz, testes[i]));
    }
    int pior = 0;
    for (int c = 1; c <= 100; c++) {
        int p = passos(raiz, c);
        if (p > pior) {
            pior = p;
        }
    }
    printf("pior caso entre as 100: %d passos (altura %d)\n", pior, rn_altura(raiz));
    raiz = rn_libera(raiz);
    return 0;
}
