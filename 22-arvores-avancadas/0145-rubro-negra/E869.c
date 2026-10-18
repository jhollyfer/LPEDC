// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E869 · ★★★
//
// Ache o bug. O cartório guarda as senhas do dia numa rubro-negra escrita à
// mão, sem o TAD. Ela tem UM erro numa das rotações. O programa insere as
// senhas 101 a 112, em ordem, e chama um fiscal que confere as regras. Rode,
// veja o fiscal reclamar e a árvore crescer demais, conserte e rode de novo.
//
//   Saída esperada:
//   pré: 108 104* 102 101 103 106 105 107 110 109 112 111*
//   altura 3, altura preta 3
//   fiscal: regras ok
//
// Dicas:
// 1. Desenhe a árvore depois de inserir 101, 102, 103 e 104 com o código como
//    está, e depois com o que a rotação deveria fazer.
// 2. Na rotação, o nó que sobe passa a receber o link que chegava no nó que
//    desce. Esse link pode ser preto ou vermelho: a cor tem que ir junto.
// 3. Resposta esperada: falta "x->vermelho = h->vermelho;" em vira_esq
//    (compare com vira_dir). Sem ela, o nó que sobe continua vermelho
//    mesmo quando ocupa o lugar de um nó preto, e o vermelho fica à direita.
//    Com a linha de volta, a saída é a de cima.
//
// Escreva sua resposta abaixo (conserte o código):

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Senha {
    int num;
    bool vermelho;
    struct Senha *esq, *dir;
} Senha;

bool vermelho(const Senha *s) {
    return s != NULL && s->vermelho;
}

Senha *vira_esq(Senha *h) {
    Senha *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    h->vermelho = true;
    return x;
}

Senha *vira_dir(Senha *h) {
    Senha *x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

Senha *insere(Senha *h, int num) {
    if (h == NULL) {
        Senha *s = malloc(sizeof(Senha));
        if (s == NULL) {
            exit(1);
        }
        s->num = num;
        s->vermelho = true;
        s->esq = s->dir = NULL;
        return s;
    }
    if (num < h->num) {
        h->esq = insere(h->esq, num);
    } else if (num > h->num) {
        h->dir = insere(h->dir, num);
    }
    if (vermelho(h->dir) && !vermelho(h->esq)) {
        h = vira_esq(h);
    }
    if (vermelho(h->esq) && vermelho(h->esq->esq)) {
        h = vira_dir(h);
    }
    if (vermelho(h->esq) && vermelho(h->dir)) {
        h->vermelho = true;
        h->esq->vermelho = false;
        h->dir->vermelho = false;
    }
    return h;
}

// devolve a altura preta, ou -1 se alguma regra estiver quebrada
int fiscal(const Senha *s) {
    if (s == NULL) {
        return 0;
    }
    if (vermelho(s->dir) || (vermelho(s) && vermelho(s->esq))) {
        return -1;
    }
    int e = fiscal(s->esq), d = fiscal(s->dir);
    if (e < 0 || d < 0 || e != d) {
        return -1;
    }
    return e + (s->vermelho ? 0 : 1);
}

int altura(const Senha *s) {
    if (s == NULL) {
        return -1;
    }
    int e = altura(s->esq), d = altura(s->dir);
    return 1 + (e > d ? e : d);
}

void pre(const Senha *s) {
    if (s != NULL) {
        printf(" %d%s", s->num, s->vermelho ? "*" : "");
        pre(s->esq);
        pre(s->dir);
    }
}

void libera(Senha *s) {
    if (s != NULL) {
        libera(s->esq);
        libera(s->dir);
        free(s);
    }
}

int main(void) {
    Senha *raiz = NULL;
    for (int num = 101; num <= 112; num++) {
        raiz = insere(raiz, num);
        raiz->vermelho = false;
    }
    printf("pré:");
    pre(raiz);
    int f = fiscal(raiz);
    int pretos = 0;
    for (const Senha *s = raiz; s != NULL; s = s->esq) {
        pretos += !s->vermelho;
    }
    printf("\naltura %d, altura preta %d\n", altura(raiz), pretos);
    printf("fiscal: %s\n", f >= 0 ? "regras ok" : "regra quebrada");
    libera(raiz);
    return 0;
}
