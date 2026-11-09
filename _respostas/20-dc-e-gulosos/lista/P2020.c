// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2020 · ★★☆ · A fila do cartório

#include <stdio.h>
#include <stdlib.h>

#define N 6

int crescente(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

double espera_media(const int d[]) {
    int espera = 0, total = 0;
    for (int i = 0; i < N; i++) {
        total += espera;
        espera += d[i];
    }
    return (double)total / N;
}

void mostra(const char *titulo, const int d[]) {
    printf("%s:", titulo);
    for (int i = 0; i < N; i++) {
        printf(" %d", d[i]);
    }
    printf(" -> espera média %.2f min\n", espera_media(d));
}

int main(void) {
    int d[N] = {12, 3, 8, 1, 20, 5};
    mostra("Ordem de chegada", d);
    qsort(d, N, sizeof d[0], crescente);
    mostra("Mais curto primeiro", d);
    return 0;
}
