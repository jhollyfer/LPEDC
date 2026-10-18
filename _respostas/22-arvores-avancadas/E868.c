// 0145 · Rubro-negra esquerdista (LLRB)
// Exercício E868 · ★★☆

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Voto {
    int numero;
    int qtd;
    bool vermelho;
    struct Voto *esq, *dir;
} Voto;

bool vermelho(const Voto *v) {
    return v != NULL && v->vermelho;
}

Voto *novo(int numero) {
    Voto *v = malloc(sizeof(Voto));
    if (v == NULL) {
        exit(1);
    }
    v->numero = numero;
    v->qtd = 1;
    v->vermelho = true;
    v->esq = v->dir = NULL;
    return v;
}

Voto *vira_esq(Voto *h) {
    Voto *x = h->dir;
    h->dir = x->esq;
    x->esq = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

Voto *vira_dir(Voto *h) {
    Voto *x = h->esq;
    h->esq = x->dir;
    x->dir = h;
    x->vermelho = h->vermelho;
    h->vermelho = true;
    return x;
}

Voto *insere(Voto *h, int numero) {
    if (h == NULL) {
        return novo(numero);
    }
    if (numero < h->numero) {
        h->esq = insere(h->esq, numero);
    } else if (numero > h->numero) {
        h->dir = insere(h->dir, numero);
    } else {
        h->qtd++; // número repetido: mais um voto
    }
    if (vermelho(h->dir) && !vermelho(h->esq)) {
        h = vira_esq(h);
    }
    if (vermelho(h->esq) && vermelho(h->esq->esq)) {
        h = vira_dir(h);
    }
    if (vermelho(h->esq) && vermelho(h->dir)) {
        h->vermelho = true;
        h->esq->vermelho = h->dir->vermelho = false;
    }
    return h;
}

void apura(const Voto *v) {
    if (v != NULL) {
        apura(v->esq);
        printf("%d: %d %s\n", v->numero, v->qtd, v->qtd == 1 ? "voto" : "votos");
        apura(v->dir);
    }
}

const Voto *vencedor(const Voto *v) {
    if (v == NULL) {
        return NULL;
    }
    const Voto *melhor = v;
    const Voto *e = vencedor(v->esq);
    const Voto *d = vencedor(v->dir);
    if (e != NULL && e->qtd > melhor->qtd) {
        melhor = e;
    }
    if (d != NULL && d->qtd > melhor->qtd) {
        melhor = d;
    }
    return melhor;
}

void libera(Voto *v) {
    if (v != NULL) {
        libera(v->esq);
        libera(v->dir);
        free(v);
    }
}

int main(void) {
    int urna[] = {45, 12, 45, 13, 30, 12, 45, 13, 45, 30, 12, 99};
    int n = 12;
    Voto *raiz = NULL;
    for (int i = 0; i < n; i++) {
        raiz = insere(raiz, urna[i]);
        raiz->vermelho = false;
    }

    apura(raiz);
    const Voto *v = vencedor(raiz);
    printf("Vencedor: %d com %d de %d votos\n", v->numero, v->qtd, n);

    libera(raiz);
    return 0;
}
