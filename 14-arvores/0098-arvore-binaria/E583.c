// 0098 · Árvore binária e percursos
// Exercício E583 · ★☆☆
//
// Monte esta árvore com arv_cria, do TAD arvore.h, e imprima os quatro
// percursos (pré-ordem, em ordem, pós-ordem e por nível), a quantidade de
// nós e a altura. Depois libere a árvore com arv_libera.
//
//   M
//   ├── esq: G
//   │   ├── esq: C
//   │   └── dir: J
//   └── dir: T
//       └── dir: X
//
//   Saída esperada:
//   Pré-ordem: M G C J T X
//   Em ordem:  C G J M T X
//   Pós-ordem: C J G X T M
//   Por nível: M G T C J X
//   Nós: 6, altura: 2
//
// Dicas:
// 1. Monte de baixo para cima: as folhas são arv_cria('C', NULL, NULL) e
//    companhia. T não tem filho esquerdo: o 2º argumento dele é NULL.
// 2. Cada função de percurso imprime um espaço antes de cada letra; use
//    printf("Pré-ordem:") e chame arv_pre_ordem(raiz) logo depois.
// 3. Resposta esperada: as 5 linhas acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include "arvore.h"

int main(void) {

    return 0;
}
