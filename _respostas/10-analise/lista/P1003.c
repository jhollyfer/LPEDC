// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1003 · ★☆☆ · O laço contra a fórmula de Gauss

#include <stdio.h>

long long soma_laco(int n, int *passos) {
    long long s = 0;
    *passos = 0;
    for (int i = 1; i <= n; i++) {
        s += i;
        (*passos)++;
    }
    return s;
}

long long soma_formula(int n, int *passos) {
    *passos = 3; // uma soma, uma multiplicação e uma divisão
    return (long long) n * (n + 1) / 2;
}

int main(void) {
    int testes[2] = {100, 100000};
    for (int i = 0; i < 2; i++) {
        int pl, pf;
        long long a = soma_laco(testes[i], &pl);
        long long b = soma_formula(testes[i], &pf);
        printf("n = %d: laço %lld (%d passos), fórmula %lld (%d passos)\n", testes[i], a, pl, b, pf);
    }
    return 0;
}
