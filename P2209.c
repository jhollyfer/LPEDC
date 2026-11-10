// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2209 · ★☆☆ · O trabalho escondido da rubro-negra
//
// A rubro-negra esquerdista (assunto 0145) mantém o equilíbrio com
// rotações e inversões de cor. Quanto trabalho é isso? O programa abaixo
// tem a inserção completa. Instrumente-o: conte as rotações à esquerda, as
// rotações à direita e as inversões de cor ao inserir os códigos de 1 a
// 15, em ordem crescente (o pior caso de uma árvore de busca comum), e
// mostre também a altura final (em nós).
//
//   Saída esperada:
//   Raiz: 8
//   Rotações à esquerda: 11
//   Rotações à direita: 0
//   Inversões de cor: 11
//   Altura: 4 nós
//
// Dicas:
// 1. Três contadores globais, um em cada função: rot_esq, rot_dir e
//    inverte.
// 2. altura(r) = 0 para NULL; senão 1 + o maior entre os dois lados.
// 3. Resposta esperada: altura 4 (uma árvore de busca comum teria 15) e os
//    contadores da saída. Em ordem crescente, nenhuma rotação à direita
//    acontece.
//
// Escreva sua resposta abaixo (estenda o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int chave;
    bool vermelho; // cor do link que vem do pai
    struct No *esq, *dir;
} No;

bool verm(const No *h) {
    return h != NULL && h->vermelho;
}

No *rot_esq(No *h) {
    No *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

No *rot_dir(No *h) {
    No *x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

void inverte(No *h) {
    h->vermelho = !h->vermelho;
    h->esq->vermelho = !h->esq->vermelho;
    h->dir->vermelho = !h->dir->vermelho;
}

No *ins(No *h, int k) {
    if (h == NULL) {
        No *n = malloc(sizeof *n);
        if (n == NULL) {
            exit(1);
        }
        *n = (No){k, true, NULL, NULL};
        return n;
    }
    if (k < h->chave) {
        h->esq = ins(h->esq, k);
    } else if (k > h->chave) {
        h->dir = ins(h->dir, k);
    }
    if (verm(h->dir) && !verm(h->esq)) {
        h = rot_esq(h);
    }
    if (verm(h->esq) && verm(h->esq->esq)) {
        h = rot_dir(h);
    }
    if (verm(h->esq) && verm(h->dir)) {
        inverte(h);
    }
    return h;
}

No *insere(No *r, int k) {
    r = ins(r, k);
    r->vermelho = false;
    return r;
}

void libera(No *r) {
    if (r != NULL) {
        libera(r->esq);
        libera(r->dir);
        free(r);
    }
}

int main(void) {
    No *r = NULL;
    for (int k = 1; k <= 15; k++) {
        r = insere(r, k);
    }
    printf("Raiz: %d\n", r->chave);
    libera(r);
    return 0;
}
