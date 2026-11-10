// 0098 · Árvore binária e percursos
// Exercício E588 · ★★★
//
// Dá para guardar uma árvore binária numa string: escreva a pré-ordem e
// marque cada subárvore vazia com um ponto. A árvore do churrasco vira
// "*-8..3..+4..2.." e a árvore M, G, T, C, J, X do E583 vira "MGC..J..T.X..".
//
// Escreva a função constroi(s, &pos), que lê a string a partir de s[pos] e
// devolve a árvore montada com arv_cria. O main testa as duas strings:
//
//   Saída esperada:
//   *-8..3..+4..2..
//     em ordem:  8 - 3 * 4 + 2
//     pós-ordem: 8 3 - 4 2 + *
//     nós: 7, altura: 2
//   MGC..J..T.X..
//     em ordem:  C G J M T X
//     pós-ordem: C J G X T M
//     nós: 6, altura: 2
//
// Escreva sua resposta abaixo (complete constroi):

#include <stdio.h>
#include "arvore.h"

No *constroi(const char *s, int *pos) {
    (void)s; // apague estas duas linhas
    (void)pos;
    return NULL;
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
