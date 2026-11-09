// 0175 · Conceitos e sucessor
// Exercício E1045 · ★☆☆

#include <stdio.h>
#include "arvpai.h"

// conta[g] recebe quantos nós têm grau g
void conta_graus(const NoP *r, int conta[3]) {
    if (r == NULL) {
        return;
    }
    conta[ap_grau(r)]++;
    conta_graus(r->esq, conta);
    conta_graus(r->dir, conta);
}

int main(void) {
    int codigos[] = {50, 30, 70, 20, 40, 60, 80, 35, 45, 65};
    NoP *raiz = NULL;
    for (int i = 0; i < 10; i++) {
        raiz = ap_insere(raiz, codigos[i]);
    }
    int conta[3] = {0, 0, 0};
    conta_graus(raiz, conta);
    int grau_arvore = 0;
    for (int g = 0; g < 3; g++) {
        printf("grau %d: %d nós\n", g, conta[g]);
        if (conta[g] > 0) {
            grau_arvore = g;
        }
    }
    printf("grau da árvore: %d | folhas: %d\n", grau_arvore, conta[0]);
    raiz = ap_libera(raiz);
    return 0;
}
