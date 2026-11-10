// Lista · Módulo 14 · Árvores
// Exercício P1414 · ★★☆ · Reconstruindo a árvore pela pós-ordem
//
// Uma árvore binária (não é BST) de números distintos foi salva em dois
// percursos:
//
//   em ordem:  4 2 7 5 1 3 6
//   pós-ordem: 4 7 5 2 6 3 1
//
// Escreva No *monta(em, ini, fim, pos, &ultimo), que reconstrói a árvore de
// em[ini..fim]. A raiz é o último elemento ainda não usado da pós-ordem
// (pos[*ultimo], e *ultimo diminui); a posição dela na em ordem separa o lado
// esquerdo do direito. Mostre a pré-ordem e a altura da árvore montada e
// libere tudo.
//
//   Saída esperada:
//   pré: 1 2 4 5 7 3 6
//   altura: 3
//
// Dicas:
// 1. Lendo a pós-ordem de trás para frente, você encontra: raiz, depois a
//    subárvore DIREITA inteira, depois a esquerda. Por isso monte o lado
//    direito antes do esquerdo.
// 2. ini > fim é a árvore vazia: devolva NULL.
// 3. Com pré + em, a ideia é a mesma lendo a pré da frente para trás (raiz,
//    esquerda, direita). Já pré + pós não bastam: elas não dizem se um filho
//    único é esquerdo ou direito.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    struct No *esq, *dir;
} No;

int main(void) {
    int em[] = {4, 2, 7, 5, 1, 3, 6};
    int pos[] = {4, 7, 5, 2, 6, 3, 1};
    (void)em;
    (void)pos;

    return 0;
}
