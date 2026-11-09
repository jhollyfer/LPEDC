// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2013 · ★★☆ · A mediana sem ordenar tudo

#include <stdio.h>
#include <string.h>

#define N 11

int particoes = 0;

int particao(int v[], int ini, int fim) {
    particoes++;
    int piv = v[fim], i = ini;
    for (int j = ini; j < fim; j++) {
        if (v[j] < piv) {
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
            i++;
        }
    }
    int t = v[i];
    v[i] = v[fim];
    v[fim] = t;
    return i;
}

int seleciona(int v[], int ini, int fim, int k) {
    if (ini == fim) {
        return v[ini];
    }
    int p = particao(v, ini, fim);
    if (p == k) {
        return v[p];
    }
    if (k < p) {
        return seleciona(v, ini, p - 1, k);
    }
    return seleciona(v, p + 1, fim, k);
}

int main(void) {
    const int orig[N] = {7, 15, 3, 22, 9, 4, 18, 11, 6, 13, 2};
    const int ks[3] = {5, 0, 10};
    for (int i = 0; i < 3; i++) {
        int v[N];
        memcpy(v, orig, sizeof v);
        particoes = 0;
        int r = seleciona(v, 0, N - 1, ks[i]);
        printf("%2dº menor: %d (partições: %d)\n", ks[i] + 1, r, particoes);
    }
    return 0;
}
