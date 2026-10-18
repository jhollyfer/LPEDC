// 0106 · AVL: balanceamento e rotações
// Exercício E634 · ★★☆
//
// A rotação à direita está pronta. Complete gira_esquerda(r), o espelho
// dela: o filho direito sobe, r desce para a esquerda, a subárvore do meio
// muda de pai e as duas alturas são recalculadas na ordem certa. Ela devolve
// a nova raiz. Os testes giram duas árvores montadas à mão:
//
//   Saída esperada:
//   Teste 1: pré 20 10 30 | altura da raiz 1
//   Teste 2: pré 60 40 20 50 70 | altura da raiz 2
//
// Dicas:
// 1. Copie gira_direita e troque esq por dir em todo lugar.
// 2. A subárvore do meio é d->esq: ela vira r->dir. Atualize primeiro r (que
//    ficou embaixo) e depois d.
// 3. Resposta esperada: a saída acima. No teste 2, o 50 era filho esquerdo
//    do 60 e passa a ser filho direito do 40.
//
// Escreva sua resposta abaixo (complete gira_esquerda):

#include <stdio.h>
#include <stdlib.h>
#include "avl.h"

void atualiza_altura(No *r) {
    int he = avl_altura(r->esq);
    int hd = avl_altura(r->dir);
    r->altura = 1 + (he > hd ? he : hd);
}

// cria um nó já com a altura certa (os filhos já existem)
No *no(int chave, No *esq, No *dir) {
    No *n = malloc(sizeof(No));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->esq = esq;
    n->dir = dir;
    atualiza_altura(n);
    return n;
}

No *gira_direita(No *r) {
    No *e = r->esq;
    r->esq = e->dir;
    e->dir = r;
    atualiza_altura(r);
    atualiza_altura(e);
    return e;
}

No *gira_esquerda(No *r) {
    return r; // troque por sua versão
}

void mostra(const char *nome, const No *r) {
    printf("%s: pré", nome);
    avl_pre_ordem(r);
    printf(" | altura da raiz %d\n", avl_altura(r));
}

int main(void) {
    No *t1 = no(10, NULL, no(20, NULL, no(30, NULL, NULL)));
    No *t2 = no(40, no(20, NULL, NULL), no(60, no(50, NULL, NULL), no(70, NULL, NULL)));

    t1 = gira_esquerda(t1);
    t2 = gira_esquerda(t2);
    mostra("Teste 1", t1);
    mostra("Teste 2", t2);

    t1 = avl_libera(t1);
    t2 = avl_libera(t2);
    return 0;
}
