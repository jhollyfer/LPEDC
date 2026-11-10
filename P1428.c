// Lista · Módulo 14 · Árvores
// Exercício P1428 · ★★★ · BST comum contra AVL na planilha ordenada
//
// A academia importou 31 alunos de uma planilha que já vinha em ordem de
// matrícula (1, 2, ..., 31). Meça o estrago numa BST comum e compare com uma
// AVL. O esqueleto traz o nó com alt, atualiza, fator e as rotações.
// Escreva:
//
//   No *insere_bst(No *r, int chave)    sem balancear
//   No *insere_avl(No *r, int chave)    com as rotações
//   int altura_real(const No *r)        percorrendo (a BST não mantém alt)
//   int comparacoes(const No *r, int x) nós visitados até achar x
//
// Insira 1..31 nas duas e, para cada uma, procure TODAS as 31 chaves: mostre
// a altura, a pior busca, o total de comparações e a média.
//
//   Saída esperada:
//   BST: altura 30, pior busca 31, total 496, média 16.00
//   AVL: altura 4, pior busca 5, total 129, média 4.16
//
// Dicas:
// 1. Na BST, cada matrícula nova é a maior até agora e vai sempre para a
//    direita: a árvore vira uma lista. Total = 1 + 2 + ... + 31 = 496.
// 2. Com 31 = 2⁵ - 1 nós, a AVL fica perfeita: 1 nó a 1 comparação, 2 a 2,
//    4 a 3, 8 a 4 e 16 a 5. Total = 1 + 4 + 12 + 32 + 80 = 129.
// 3. A insere_avl pode reaproveitar insere_bst(NULL, chave) para criar
//    o nó.
// 4. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo:

#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave, alt;
    struct No *esq, *dir;
} No;

int alt(const No *p) {
    return p == NULL ? -1 : p->alt;
}

void atualiza(No *p) {
    int he = alt(p->esq), hd = alt(p->dir);
    p->alt = 1 + (he > hd ? he : hd);
}

int fator(const No *p) {
    return alt(p->esq) - alt(p->dir);
}

No *gira_dir(No *r) {
    No *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza(r);
    atualiza(e);
    return e;
}

No *gira_esq(No *r) {
    No *d = r->dir;
    r->dir = d->esq;
    d->esq = r;
    atualiza(r);
    atualiza(d);
    return d;
}

int main(void) {

    return 0;
}
