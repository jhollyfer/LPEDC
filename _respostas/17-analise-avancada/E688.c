// 0115 · Teorema mestre
// Exercício E688 · ★★☆

#include <stdio.h>

#define N 1000000

int v[N];
long comparacoes = 0;

// T(n) = T(n/2) + 2: até 2 comparações por chamada
int binaria(int ini, int fim, int x) {
    if (ini >= fim) {
        return -1;
    }
    int meio = ini + (fim - ini) / 2;
    comparacoes++;
    if (x == v[meio]) {
        return meio;
    }
    comparacoes++;
    if (x < v[meio]) {
        return binaria(ini, meio, x);
    }
    return binaria(meio + 1, fim, x);
}

// T(n) = T(n/3) + 4: até 4 comparações por chamada
int ternaria(int ini, int fim, int x) {
    if (ini >= fim) {
        return -1;
    }
    int terco = (fim - ini) / 3;
    int m1 = ini + terco;
    int m2 = fim - 1 - terco;
    comparacoes++;
    if (x == v[m1]) {
        return m1;
    }
    comparacoes++;
    if (x == v[m2]) {
        return m2;
    }
    comparacoes++;
    if (x < v[m1]) {
        return ternaria(ini, m1, x);
    }
    comparacoes++;
    if (x > v[m2]) {
        return ternaria(m2 + 1, fim, x);
    }
    return ternaria(m1 + 1, m2, x);
}

int main(void) {
    for (int i = 0; i < N; i++) {
        v[i] = 2 * i; // só pares
    }

    long total_bin = 0, total_ter = 0;
    for (int i = 0; i < 1000; i++) {
        int x = 2 * (int)(((long)i * 7919) % N) + 1; // ímpar: não está no vetor
        comparacoes = 0;
        binaria(0, N, x);
        total_bin += comparacoes;
        comparacoes = 0;
        ternaria(0, N, x);
        total_ter += comparacoes;
    }
    printf("binária: %.1f comparações por busca\n", total_bin / 1000.0);
    printf("ternária: %.1f comparações por busca\n", total_ter / 1000.0);
    return 0;
}
