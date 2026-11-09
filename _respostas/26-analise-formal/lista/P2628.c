// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2628 · ★★★ · Estimando o expoente

#include <stdio.h>
#include <math.h>

long passos = 0;

void funcao_a(long n) {
    for (long i = 0; i < n; i++) {
        for (long j = 0; j * j < i; j++) {
            passos++;
        }
    }
}

void funcao_b(long n) {
    for (long i = 0; i < n; i++) {
        for (long j = 0; j < i; j++) {
            passos++;
        }
    }
}

void funcao_c(long n) {
    for (long i = 1; i < n; i *= 2) {
        for (long j = 0; j < n; j++) {
            passos++;
        }
    }
}

int main(void) {
    void (*f[3])(long) = {funcao_a, funcao_b, funcao_c};
    for (int k = 0; k < 3; k++) {
        passos = 0;
        f[k](4096);
        long p1 = passos;
        passos = 0;
        f[k](8192);
        long p2 = passos;
        printf("%c: %8ld -> %8ld, p = %.3f\n", 'a' + k, p1, p2, log2((double)p2 / p1));
    }
    return 0;
}
