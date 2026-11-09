// Lista · Módulo 12 · Pilhas e filas
// Exercício P1224 · ★★★ · A Torre de Hanói sem recursão

#include <stdio.h>

typedef struct {
    int v[10];
    int n;
    char nome;
} Pino;

int topo(const Pino *p) {
    return p->n > 0 ? p->v[p->n - 1] : 99; // pino vazio aceita qualquer disco
}

void move(Pino *de, Pino *para, int *contador) {
    int disco = de->v[--de->n];
    para->v[para->n++] = disco;
    (*contador)++;
    printf("%d. disco %d: %c -> %c\n", *contador, disco, de->nome, para->nome);
}

// o único movimento permitido entre os dois pinos
void movimento_legal(Pino *x, Pino *y, int *contador) {
    if (topo(x) < topo(y)) {
        move(x, y, contador);
    } else {
        move(y, x, contador);
    }
}

int main(void) {
    int n = 3;
    Pino a = {.n = 0, .nome = 'A'}, b = {.n = 0, .nome = 'B'}, c = {.n = 0, .nome = 'C'};
    for (int d = n; d >= 1; d--) {
        a.v[a.n++] = d;
    }
    Pino *pares[3][2];
    if (n % 2 == 1) {
        pares[0][0] = &a, pares[0][1] = &c;
        pares[1][0] = &a, pares[1][1] = &b;
    } else {
        pares[0][0] = &a, pares[0][1] = &b;
        pares[1][0] = &a, pares[1][1] = &c;
    }
    pares[2][0] = &b, pares[2][1] = &c;

    int contador = 0;
    for (int k = 0; c.n < n; k = (k + 1) % 3) {
        movimento_legal(pares[k][0], pares[k][1], &contador);
    }
    printf("Pino C (de baixo para cima):");
    for (int i = 0; i < c.n; i++) {
        printf(" %d", c.v[i]);
    }
    printf("\n");
    return 0;
}
