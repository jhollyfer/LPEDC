// 0098 · Árvore binária e percursos
// Exercício E586 · ★★☆

#include <stdio.h>
#include "arvore.h"

void deitada(const No *r, int nivel) {
    if (r == NULL) {
        return;
    }
    deitada(r->dir, nivel + 1); // a direita fica em cima
    printf("%*s%c\n", 4 * nivel, "", r->info);
    deitada(r->esq, nivel + 1);
}

int main(void) {
    No *raiz = arv_cria('*',
                        arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL)),
                        arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL)));

    deitada(raiz, 0);

    raiz = arv_libera(raiz);
    return 0;
}
