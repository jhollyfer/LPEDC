// 0098 · Árvore binária e percursos
// Exercício E588 · ★★★

#include <stdio.h>
#include "arvore.h"

No *constroi(const char *s, int *pos) {
    char c = s[(*pos)++];
    if (c == '.') {
        return NULL; // subárvore vazia
    }
    No *esq = constroi(s, pos); // primeiro a esquerda...
    No *dir = constroi(s, pos); // ...depois a direita
    return arv_cria(c, esq, dir);
}

int main(void) {
    const char *testes[] = {"*-8..3..+4..2..", "MGC..J..T.X.."};
    for (int i = 0; i < 2; i++) {
        int pos = 0;
        No *raiz = constroi(testes[i], &pos);
        printf("%s\n  em ordem: ", testes[i]);
        arv_em_ordem(raiz);
        printf("\n  pós-ordem:");
        arv_pos_ordem(raiz);
        printf("\n  nós: %d, altura: %d\n", arv_conta(raiz), arv_altura(raiz));
        raiz = arv_libera(raiz);
    }
    return 0;
}
