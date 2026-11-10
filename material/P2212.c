// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2212 · ★★☆ · A árvore 2-3 escondida na rubro-negra
//
// Toda rubro-negra esquerdista é uma árvore 2-3 desenhada com cores: um nó
// com filho esquerdo VERMELHO é, junto com esse filho, um único nó 3 com
// duas chaves. O programa abaixo insere 10, 20, ..., 90 numa LLRB.
// Escreva mostra23(h, nivel), que percorre a LLRB e mostra a árvore 2-3
// correspondente, em pré-ordem, com 2 espaços de recuo por nível: um nó 2
// sai como [k]; um nó 3, como [a b], e seus três filhos são o esquerdo e o
// direito do vermelho e o direito de h.
//
//   Saída esperada:
//   [40]
//     [20]
//       [10]
//       [30]
//     [60 80]
//       [50]
//       [70]
//       [90]
//
// Dicas:
// 1. Se verm(h->esq): mostre [h->esq->chave h->chave] e desça em
//    h->esq->esq, h->esq->dir e h->dir, todos com nivel + 1.
// 2. Senão, mostre [h->chave] e desça em h->esq e h->dir.
// 3. Resposta esperada: a 2-3 de cima. Todas as folhas estão no
//    mesmo nível, e é esse equilíbrio perfeito da 2-3 que garante a altura
//    O(lg n) da rubro-negra.
//
// Escreva sua resposta abaixo (complete o código):

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

void mostra23(const No *h, int nivel) {
    (void)h;
    (void)nivel;
    // COMPLETE AQUI
}

int main(void) {
    No *r = NULL;
    for (int k = 10; k <= 90; k += 10) {
        r = insere(r, k);
    }
    mostra23(r, 0);
    libera(r);
    return 0;
}
