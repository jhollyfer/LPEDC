// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2213 · ★★☆ · Quantas divisões custa encher a árvore B

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define MAXT 4
#define MAXK (2 * MAXT - 1)

int t; // grau mínimo atual
int divisoes;

typedef struct NoB {
    int n;
    int chave[MAXK];
    struct NoB *filho[MAXK + 1];
    bool folha;
} NoB;

NoB *novo_no(bool folha) {
    NoB *x = calloc(1, sizeof *x);
    if (x == NULL) {
        exit(1);
    }
    x->folha = folha;
    return x;
}

void divide(NoB *x, int i) {
    divisoes++;
    NoB *y = x->filho[i];
    NoB *z = novo_no(y->folha);
    z->n = t - 1;
    for (int j = 0; j < t - 1; j++) {
        z->chave[j] = y->chave[j + t];
    }
    if (!y->folha) {
        for (int j = 0; j < t; j++) {
            z->filho[j] = y->filho[j + t];
        }
    }
    y->n = t - 1;
    for (int j = x->n; j > i; j--) {
        x->filho[j + 1] = x->filho[j];
    }
    x->filho[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) {
        x->chave[j + 1] = x->chave[j];
    }
    x->chave[i] = y->chave[t - 1];
    x->n++;
}

void insere_nao_cheio(NoB *x, int k) {
    int i = x->n - 1;
    if (x->folha) {
        while (i >= 0 && k < x->chave[i]) {
            x->chave[i + 1] = x->chave[i];
            i--;
        }
        x->chave[i + 1] = k;
        x->n++;
        return;
    }
    while (i >= 0 && k < x->chave[i]) {
        i--;
    }
    i++;
    if (x->filho[i]->n == 2 * t - 1) {
        divide(x, i);
        if (k > x->chave[i]) {
            i++;
        }
    }
    insere_nao_cheio(x->filho[i], k);
}

NoB *insere(NoB *r, int k) {
    if (r == NULL) {
        r = novo_no(true);
    }
    if (r->n == 2 * t - 1) {
        NoB *s = novo_no(false);
        s->filho[0] = r;
        divide(s, 0);
        insere_nao_cheio(s, k);
        return s;
    }
    insere_nao_cheio(r, k);
    return r;
}

void libera(NoB *x) {
    if (x != NULL) {
        for (int i = 0; i <= x->n; i++) {
            libera(x->filho[i]);
        }
        free(x);
    }
}

int nos(const NoB *x) {
    if (x == NULL) {
        return 0;
    }
    int c = 1;
    if (!x->folha) {
        for (int i = 0; i <= x->n; i++) {
            c += nos(x->filho[i]);
        }
    }
    return c;
}

int altura(const NoB *x) {
    int h = 0;
    while (!x->folha) {
        x = x->filho[0];
        h++;
    }
    return h;
}

int main(void) {
    for (t = 2; t <= MAXT; t++) {
        divisoes = 0;
        NoB *r = NULL;
        for (int k = 1; k <= 40; k++) {
            r = insere(r, k);
        }
        printf("t = %d: %d divisões, %d nós, altura %d\n", t, divisoes, nos(r), altura(r));
        libera(r);
    }
    return 0;
}
