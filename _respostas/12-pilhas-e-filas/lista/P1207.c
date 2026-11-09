// Lista · Módulo 12 · Pilhas e filas
// Exercício P1207 · ★☆☆ · A pilha de bandejas que transborda

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

#define CAP 4

typedef struct {
    int *v;
    int n;
} Pilha;

bool empilha(Pilha *p, int x) {
    if (p->n >= CAP) { // com n == CAP já não há posição livre
        return false;
    }
    p->v[p->n++] = x;
    return true;
}

bool desempilha(Pilha *p, int *x) {
    if (p->n == 0) {
        return false;
    }
    *x = p->v[--p->n]; // o topo é v[n - 1]
    return true;
}

int main(void) {
    Pilha p = {malloc(CAP * sizeof(int)), 0};
    if (p.v == NULL) {
        return 1;
    }
    for (int b = 1; b <= 5; b++) {
        printf("empilha %d: %s\n", b, empilha(&p, b) ? "ok" : "pilha cheia");
    }
    printf("desempilha:");
    int x;
    while (desempilha(&p, &x)) {
        printf(" %d", x);
    }
    printf("\n");
    free(p.v);
    return 0;
}
