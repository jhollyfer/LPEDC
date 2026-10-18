// heap.c · implementação do TAD heap de máximo
#include <stdio.h>
#include <stdlib.h>
#include "heap.h"

Heap *heap_cria(int cap) {
    Heap *h = malloc(sizeof(Heap));
    if (h == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    h->v = malloc(cap * sizeof(int));
    if (h->v == NULL) {
        fprintf(stderr, "sem memória\n");
        exit(1);
    }
    h->n = 0;
    h->cap = cap;
    return h;
}

static void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// o elemento em i sobe enquanto for maior que o pai
static void sobe(Heap *h, int i) {
    while (i > 0 && h->v[(i - 1) / 2] < h->v[i]) {
        troca(&h->v[(i - 1) / 2], &h->v[i]);
        i = (i - 1) / 2;
    }
}

// o elemento em i desce, trocando com o MAIOR dos filhos
static void desce(Heap *h, int i) {
    while (2 * i + 1 < h->n) {
        int f = 2 * i + 1;                       // filho esquerdo
        if (f + 1 < h->n && h->v[f + 1] > h->v[f]) {
            f++;                                 // o direito é maior
        }
        if (h->v[i] >= h->v[f]) {
            break;                               // já está no lugar
        }
        troca(&h->v[i], &h->v[f]);
        i = f;
    }
}

bool heap_insere(Heap *h, int x) {
    if (h->n == h->cap) {
        return false;
    }
    h->v[h->n] = x; // entra no fim do vetor (a próxima vaga da árvore)
    sobe(h, h->n);
    h->n++;
    return true;
}

int heap_remove(Heap *h) {
    int max = h->v[0];
    h->n--;
    h->v[0] = h->v[h->n]; // o último vai para a raiz...
    desce(h, 0);          // ...e desce até o lugar dele
    return max;
}

int heap_topo(const Heap *h) {
    return h->v[0];
}

bool heap_vazio(const Heap *h) {
    return h->n == 0;
}

void heap_mostra(const Heap *h) {
    printf("[");
    for (int i = 0; i < h->n; i++) {
        printf(i == 0 ? "%d" : " %d", h->v[i]);
    }
    printf("]");
}

void heap_libera(Heap *h) {
    free(h->v);
    free(h);
}
