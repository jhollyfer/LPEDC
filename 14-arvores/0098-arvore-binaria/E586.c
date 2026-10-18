// 0098 · Árvore binária e percursos
// Exercício E586 · ★★☆
//
// Escreva a função deitada(r, nivel), que desenha a árvore deitada no
// terminal: a raiz fica na coluna 0, e cada nível desce 4 espaços para a
// direita. A subárvore da DIREITA aparece em cima e a da esquerda embaixo,
// como se você girasse o desenho 90 graus para a esquerda. Para a árvore
// (8 - 3) * (4 + 2):
//
//   Saída esperada:
//           2
//       +
//           4
//   *
//           3
//       -
//           8
//
// Dicas:
// 1. É uma em ordem ao contrário: direita, raiz, esquerda.
// 2. Para recuar, use printf("%*s%c\n", 4 * nivel, "", r->info).
// 3. Resposta esperada: o desenho acima (7 linhas; o '*' sem recuo, '+' e '-'
//    com 4 espaços, os números com 8).
//
// Escreva sua resposta abaixo (complete deitada):

#include <stdio.h>
#include "arvore.h"

void deitada(const No *r, int nivel) {
    (void)r; // apague estas duas linhas
    (void)nivel;
}

int main(void) {
    No *raiz = arv_cria('*',
                        arv_cria('-', arv_cria('8', NULL, NULL), arv_cria('3', NULL, NULL)),
                        arv_cria('+', arv_cria('4', NULL, NULL), arv_cria('2', NULL, NULL)));

    deitada(raiz, 0);

    raiz = arv_libera(raiz);
    return 0;
}
