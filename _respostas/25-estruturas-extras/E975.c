// 0163 · Skip list
// Exercício E975 · ★★☆

#include <stdio.h>
#include "skip.h"

#define N 4000

unsigned proximo(unsigned *estado) {
    *estado = *estado * 1103515245u + 12345u;
    return *estado;
}

int sorteia(unsigned *estado, int lados) {
    int andares = 1;
    while (andares < SKIP_MAX && (proximo(estado) >> 16) % lados == 0) {
        andares++;
    }
    return andares;
}

void experimento(int lados) {
    unsigned estado = 7;
    Skip *s = skip_cria(0);
    int ponteiros = 0;
    for (int i = 1; i <= N; i++) {
        int a = sorteia(&estado, lados);
        skip_insere_andares(s, i, a);
        ponteiros += a;
    }
    long total = 0;
    for (int i = 1; i <= N; i++) {
        int passos;
        skip_busca(s, i, &passos);
        total += passos;
    }
    printf("1/%d: %d ponteiros, %.1f nós olhados por busca\n", lados, ponteiros, total / (double)N);
    skip_libera(s);
}

int main(void) {
    experimento(2);
    experimento(4);
    return 0;
}
