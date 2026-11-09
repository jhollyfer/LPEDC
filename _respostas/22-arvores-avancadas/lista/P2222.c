// Lista · Módulo 22 · Árvores e conjuntos avançados
// Exercício P2222 · ★★★ · A árvore B dos códigos de rastreio

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define T 2
#define MAXC (2 * T - 1)

typedef struct NoB {
    int n;
    int chave[MAXC];
    struct NoB *filho[MAXC + 1];
    bool folha;
} NoB;

NoB *novo_no(bool folha) {
    NoB *x = malloc(sizeof *x);
    if (x == NULL) {
        exit(1);
    }
    x->n = 0;
    x->folha = folha;
    for (int i = 0; i <= MAXC; i++) {
        x->filho[i] = NULL;
    }
    return x;
}

// o filho i de x está cheio: a chave do meio sobe para x
void divide(NoB *x, int i) {
    NoB *y = x->filho[i];
    NoB *z = novo_no(y->folha);
    z->n = T - 1;
    for (int j = 0; j < T - 1; j++) {
        z->chave[j] = y->chave[j + T];
    }
    if (!y->folha) {
        for (int j = 0; j < T; j++) {
            z->filho[j] = y->filho[j + T];
        }
    }
    y->n = T - 1;
    for (int j = x->n; j > i; j--) {
        x->filho[j + 1] = x->filho[j];
    }
    x->filho[i + 1] = z;
    for (int j = x->n - 1; j >= i; j--) {
        x->chave[j + 1] = x->chave[j];
    }
    x->chave[i] = y->chave[T - 1];
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
    if (x->filho[i]->n == MAXC) {
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
    if (r->n == MAXC) {
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
    if (x == NULL) {
        return;
    }
    for (int i = 0; i <= x->n; i++) {
        libera(x->filho[i]);
    }
    free(x);
}

int busca(const NoB *x, int k, int *visitados) {
    while (x != NULL) {
        (*visitados)++;
        int i = 0;
        while (i < x->n && k > x->chave[i]) {
            i++;
        }
        if (i < x->n && x->chave[i] == k) {
            return 1;
        }
        if (x->folha) {
            return 0;
        }
        x = x->filho[i];
    }
    return 0;
}

void niveis(NoB *r) {
    NoB *fila[64];
    int nivel[64], ini = 0, fim = 0, atual = -1;
    fila[fim] = r;
    nivel[fim++] = 0;
    while (ini < fim) {
        NoB *x = fila[ini];
        int nv = nivel[ini++];
        if (nv != atual) {
            if (atual >= 0) {
                printf("\n");
            }
            atual = nv;
            printf("Nível %d:", nv);
        }
        printf(" [");
        for (int i = 0; i < x->n; i++) {
            printf(i ? " %d" : "%d", x->chave[i]);
        }
        printf("]");
        if (!x->folha) {
            for (int i = 0; i <= x->n; i++) {
                fila[fim] = x->filho[i];
                nivel[fim++] = nv + 1;
            }
        }
    }
    printf("\n");
}

int main(void) {
    const int cod[18] = {41, 17, 88, 5, 63, 29, 72, 95, 12, 57, 34, 80, 3, 66, 21, 48, 99, 9};
    NoB *r = NULL;
    for (int i = 0; i < 18; i++) {
        r = insere(r, cod[i]);
    }
    niveis(r);
    int h = 0;
    for (const NoB *x = r; !x->folha; x = x->filho[0]) {
        h++;
    }
    printf("Altura: %d\n", h);
    const int procura[2] = {57, 60};
    for (int i = 0; i < 2; i++) {
        int vis = 0;
        int achou = busca(r, procura[i], &vis);
        printf("Busca %d: %s (nós visitados: %d)\n", procura[i], achou ? "achou" : "não achou", vis);
    }
    libera(r);
    return 0;
}
