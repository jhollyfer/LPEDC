// 0172 · Vetor de tamanho variável (VLA)
// Exercício E1032 · ★★★

#include <stdio.h>
#include <stdlib.h>

long long somar(const long long *v, int n) {
    long long soma = 0;
    for (int i = 0; i < n; i++) {
        soma += v[i];
    }
    return soma;
}

void quadrados(long long *v, int n) {
    for (int i = 0; i < n; i++) {
        v[i] = (long long)(i + 1) * (i + 1);
    }
}

long long soma_quadrados(int n) {
    if (n <= 0) {
        return -1; // VLA de tamanho <= 0 seria indefinido
    }
    if (n <= 1000) {
        long long v[n]; // pequeno e conferido: pilha
        printf("pilha, ");
        quadrados(v, n);
        return somar(v, n);
    }
    long long *v = malloc(n * sizeof *v); // grande: heap
    if (v == NULL) {
        return -1;
    }
    printf("heap, ");
    quadrados(v, n);
    long long soma = somar(v, n);
    free(v);
    return soma;
}

int main(void) {
    int testes[] = {0, 10, 100000};
    for (int i = 0; i < 3; i++) {
        printf("n = %d: ", testes[i]);
        long long s = soma_quadrados(testes[i]);
        if (s < 0) {
            printf("invalido\n");
        } else {
            printf("soma = %lld\n", s);
        }
    }
    return 0;
}
