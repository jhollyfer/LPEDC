// 0165 · Juntando tudo
// Exercício E987 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include "bancada.h"

#define N 1000
#define BUSCAS 10000
#define QUENTES 20
#define BALDES 101

typedef struct NoH {
    int chave;
    struct NoH *prox;
} NoH;

typedef struct {
    NoH *balde[BALDES];
} Hash;

void *hash_cria(void) {
    Hash *h = malloc(sizeof(Hash));
    if (h == NULL) {
        exit(1);
    }
    for (int i = 0; i < BALDES; i++) {
        h->balde[i] = NULL;
    }
    return h;
}

void hash_insere(void *e, int chave) {
    Hash *h = e;
    int b = chave % BALDES;
    for (const NoH *p = h->balde[b]; p != NULL; p = p->prox) {
        if (p->chave == chave) {
            return;
        }
    }
    NoH *n = malloc(sizeof(NoH));
    if (n == NULL) {
        exit(1);
    }
    n->chave = chave;
    n->prox = h->balde[b]; // entra no início do balde
    h->balde[b] = n;
}

bool hash_busca(void *e, int chave, int *custo) {
    const Hash *h = e;
    int c = 0;
    for (const NoH *p = h->balde[chave % BALDES]; p != NULL; p = p->prox) {
        c++;
        if (p->chave == chave) {
            *custo = c;
            return true;
        }
    }
    *custo = c;
    return false;
}

void hash_libera(void *e) {
    Hash *h = e;
    for (int i = 0; i < BALDES; i++) {
        NoH *p = h->balde[i];
        while (p != NULL) {
            NoH *prox = p->prox;
            free(p);
            p = prox;
        }
    }
    free(h);
}

double mede(const Estrutura *e, const int ordem[], const int buscas[]) {
    void *d = e->cria();
    for (int i = 0; i < N; i++) {
        e->insere(d, ordem[i]);
    }
    long total = 0;
    for (int i = 0; i < BUSCAS; i++) {
        int custo;
        e->busca(d, buscas[i], &custo);
        total += custo;
    }
    e->libera(d);
    return (double)total / BUSCAS;
}

int main(void) {
    unsigned estado = 7;
    int crescente[N], embaralhada[N], sorteio[N];
    for (int i = 0; i < N; i++) {
        crescente[i] = embaralhada[i] = sorteio[i] = i + 1;
    }
    bc_embaralha(embaralhada, N, &estado);
    bc_embaralha(sorteio, N, &estado);
    static int buscas[BUSCAS];
    for (int i = 0; i < BUSCAS; i++) {
        if (bc_sorteio(&estado) % 100 < 80) {
            buscas[i] = sorteio[bc_sorteio(&estado) % QUENTES];
        } else {
            buscas[i] = bc_sorteio(&estado) % N + 1;
        }
    }

    Estrutura todos[NUM_CONCORRENTES + 1];
    for (int k = 0; k < NUM_CONCORRENTES; k++) {
        todos[k] = CONCORRENTES[k];
    }
    todos[NUM_CONCORRENTES] = (Estrutura){"hash", hash_cria, hash_insere, hash_busca, hash_libera};

    printf("%-10s %12s %10s\n", "", "embaralhada", "crescente");
    for (int k = 0; k <= NUM_CONCORRENTES; k++) {
        printf("%-10s %12.1f %10.1f\n", todos[k].nome, mede(&todos[k], embaralhada, buscas),
               mede(&todos[k], crescente, buscas));
    }
    return 0;
}
