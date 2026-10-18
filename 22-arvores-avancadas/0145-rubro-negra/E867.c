// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E867 · ★★☆
//
// Escreva confere(r), o fiscal da rubro-negra esquerdista. Ela devolve a
// altura preta (quantos nós pretos há da raiz até um NULL) se as três regras
// valerem, ou um código negativo dizendo a primeira regra quebrada que achar:
//   -1: um link vermelho à direita;
//   -2: dois vermelhos seguidos (um vermelho com filho esquerdo vermelho);
//   -3: dois caminhos com quantidades diferentes de nós pretos.
// O main já monta quatro árvores: uma pelo TAD e três à mão, com no().
//
//   Saída esperada:
//   TAD (1 a 20): ok, altura preta 4
//   Árvore A: quebra a regra 1
//   Árvore B: quebra a regra 2
//   Árvore C: quebra a regra 3
//
// Dicas:
// 1. NULL devolve 0 (é preto, mas não conta). Se r->dir é vermelho, -1. Se
//    r e r->esq são vermelhos, -2.
// 2. Peça confere das duas subárvores; se alguma for negativa, repasse. Se
//    forem diferentes, -3. Senão, devolva o valor + (r é preto ? 1 : 0).
// 3. Resposta esperada: a saída acima. Cada nó é visitado uma vez só: O(n).
//
// Escreva sua resposta abaixo (escreva confere):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include "rubronegra.h"

NoRN *no(int chave, bool vermelho, NoRN *esq, NoRN *dir) {
    NoRN *n = malloc(sizeof(NoRN));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->vermelho = vermelho;
    n->esq = esq;
    n->dir = dir;
    return n;
}

int confere(const NoRN *r) {
    (void)r; // apague esta linha
    return 0;
}

void relata(const char *nome, const NoRN *r) {
    int c = confere(r);
    if (c >= 0) {
        printf("%s: ok, altura preta %d\n", nome, c);
    } else {
        printf("%s: quebra a regra %d\n", nome, -c);
    }
}

int main(void) {
    NoRN *tad = NULL;
    for (int c = 1; c <= 20; c++) {
        tad = rn_insere(tad, c);
    }
    // A: 20 com 10 (preto) à esquerda e 30 (VERMELHO) à direita
    NoRN *a = no(20, false, no(10, false, NULL, NULL), no(30, true, NULL, NULL));
    // B: 30 com 20 vermelho à esquerda, e 10 vermelho embaixo do 20
    NoRN *b = no(30, false, no(20, true, no(10, true, NULL, NULL), NULL),
                 no(40, false, NULL, NULL));
    // C: tudo preto, mas o 10 tem um filho (5) e o 30 não tem nenhum
    NoRN *c = no(20, false, no(10, false, no(5, false, NULL, NULL), NULL),
                 no(30, false, NULL, NULL));

    relata("TAD (1 a 20)", tad);
    relata("Árvore A", a);
    relata("Árvore B", b);
    relata("Árvore C", c);

    tad = rn_libera(tad);
    a = rn_libera(a);
    b = rn_libera(b);
    c = rn_libera(c);
    return 0;
}
