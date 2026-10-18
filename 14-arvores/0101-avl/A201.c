// A201 · Os quatro casos, três chaves cada

#include <stdio.h>
#include "avl.h"

// insere as três chaves numa AVL nova e mostra quantas rotações custou
void testa(const char *caso, int a, int b, int c) {
    int antes = avl_rotacoes(); // o contador é um só para o programa todo
    No *r = NULL;
    r = avl_insere(r, a);
    r = avl_insere(r, b);
    r = avl_insere(r, c);
    printf("%-18s %d %d %d -> pré", caso, a, b, c);
    avl_pre_ordem(r);
    printf(" | rotações %d\n", avl_rotacoes() - antes);
    r = avl_libera(r);
}

int main(void) {
    // em linha reta: uma rotação simples resolve
    testa("esquerda-esquerda", 30, 20, 10);
    testa("direita-direita", 10, 20, 30);
    // em zigue-zague: primeiro endireita o filho, depois gira o avô
    testa("esquerda-direita", 30, 10, 20);
    testa("direita-esquerda", 10, 30, 20);
    // nenhum desequilíbrio: o do meio chegou primeiro
    testa("nenhum caso", 20, 10, 30);
    return 0;
}
// Saída:
// esquerda-esquerda  30 20 10 -> pré 20 10 30 | rotações 1
// direita-direita    10 20 30 -> pré 20 10 30 | rotações 1
// esquerda-direita   30 10 20 -> pré 20 10 30 | rotações 2
// direita-esquerda   10 30 20 -> pré 20 10 30 | rotações 2
// nenhum caso        20 10 30 -> pré 20 10 30 | rotações 0
