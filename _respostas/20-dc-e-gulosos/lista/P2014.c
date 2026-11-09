// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2014 · ★★☆ · Quantas salas para o congresso?

#include <stdio.h>
#include <stdlib.h>

#define N 9

typedef struct {
    int ini, fim;
} Palestra;

int compara(const void *a, const void *b) {
    const Palestra *p = a, *q = b;
    if (p->ini != q->ini) {
        return p->ini - q->ini;
    }
    return p->fim - q->fim;
}

int main(void) {
    Palestra p[N] = {{9, 11}, {9, 10}, {10, 12}, {11, 13}, {10, 11}, {12, 14}, {13, 15}, {9, 12}, {14, 16}};
    qsort(p, N, sizeof p[0], compara);
    int livre_em[N], salas = 0;
    for (int i = 0; i < N; i++) {
        int s = 0;
        while (s < salas && livre_em[s] > p[i].ini) {
            s++;
        }
        if (s == salas) {
            salas++;
        }
        livre_em[s] = p[i].fim;
        printf("[%d, %d) -> sala %d\n", p[i].ini, p[i].fim, s + 1);
    }
    printf("Salas: %d\n", salas);
    return 0;
}
