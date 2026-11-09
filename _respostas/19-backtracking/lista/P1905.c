// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1905 · ★☆☆ · Os sócios que sumiram da mesa

#include <stdio.h>

#define N 3

const char *v[N] = {"Ana", "Bia", "Caio"};
int total = 0;

void troca(int a, int b) {
    const char *t = v[a];
    v[a] = v[b];
    v[b] = t;
}

void permuta(int k) {
    if (k == N) {
        total++;
        printf("%s %s %s\n", v[0], v[1], v[2]);
        return;
    }
    for (int i = k; i < N; i++) {
        troca(k, i);
        permuta(k + 1);
        troca(k, i);
    }
}

int main(void) {
    permuta(0);
    printf("%d ordens\n", total);
    return 0;
}
