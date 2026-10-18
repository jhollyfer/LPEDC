// 0106 · AVL: balanceamento e rotações
// Exercício E633 · ★★☆
//
// Escreva altura_se_avl(r): ela devolve a altura da árvore se ela respeitar a
// regra da AVL em todos os nós, ou -2 se algum nó tiver fator fora de
// -1..1. A árvore aqui é uma árvore binária simples, sem campo de altura (o
// struct Arv do próprio arquivo). Regra extra: visite cada nó UMA vez só.
//
// O main testa a árvore do E631 e a versão consertada dela:
//
//   Saída esperada:
//   Árvore 1: não é AVL
//   Árvore 2: é AVL, altura 3
//
// Dicas:
// 1. A solução ingênua chama uma função altura() em cada nó, e cada chamada
//    percorre a subárvore de novo: O(n²). Calcule a altura e confira o
//    fator na mesma volta da recursão.
// 2. Vazia devolve -1. Peça a altura das duas subárvores; se alguma vier -2,
//    devolva -2. Se a diferença passar de 1, devolva -2. Senão, devolva
//    1 + a maior.
// 3. Resposta esperada: a saída acima.
//
// Escreva sua resposta abaixo (complete altura_se_avl):

#include <stdio.h>
#include <stdlib.h>

typedef struct Arv {
    int chave;
    struct Arv *esq, *dir;
} Arv;

Arv *no(int chave, Arv *esq, Arv *dir) {
    Arv *n = malloc(sizeof(Arv));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->esq = esq;
    n->dir = dir;
    return n;
}

void libera(Arv *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int altura_se_avl(const Arv *r) {
    (void)r; // apague esta linha
    return -2;
}

void testa(const char *nome, const Arv *r) {
    int h = altura_se_avl(r);
    if (h == -2) {
        printf("%s: não é AVL\n", nome);
    } else {
        printf("%s: é AVL, altura %d\n", nome, h);
    }
}

int main(void) {
    Arv *a1 = no(50, no(30, no(20, no(10, NULL, NULL), NULL), no(40, NULL, NULL)),
                 no(70, NULL, no(80, NULL, no(90, NULL, NULL))));
    Arv *a2 = no(50, no(30, no(20, no(10, NULL, NULL), NULL), no(40, NULL, NULL)),
                 no(80, no(70, NULL, NULL), no(90, NULL, NULL)));
    testa("Árvore 1", a1);
    testa("Árvore 2", a2);
    libera(a1);
    libera(a2);
    return 0;
}
