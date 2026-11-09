// Lista · Módulo 12 · Pilhas e filas
// Exercício P1201 · ★☆☆ · O painel de LEDs em binário

#include <stdbool.h>
#include <stdio.h>

#define CAP 32

typedef struct {
    int v[CAP];
    int n; // quantos itens; o topo é v[n - 1]
} Pilha;

bool empilha(Pilha *p, int x) {
    if (p->n == CAP) {
        return false;
    }
    p->v[p->n++] = x;
    return true;
}

bool desempilha(Pilha *p, int *x) {
    if (p->n == 0) {
        return false;
    }
    *x = p->v[--p->n];
    return true;
}

bool vazia(const Pilha *p) {
    return p->n == 0;
}

void binario(int n) {
    Pilha p = {.n = 0};
    int original = n;
    do {
        empilha(&p, n % 2);
        n /= 2;
    } while (n > 0);
    printf("%d = ", original);
    int bit;
    while (!vazia(&p) && desempilha(&p, &bit)) {
        printf("%d", bit);
    }
    printf("\n");
}

int main(void) {
    int numeros[4] = {13, 156, 1024, 0};
    for (int i = 0; i < 4; i++) {
        binario(numeros[i]);
    }
    return 0;
}
