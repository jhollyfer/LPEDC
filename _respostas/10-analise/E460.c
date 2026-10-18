// 0077 · Notação O: como o custo cresce
// Exercício E460 · ★★☆
//
// Resposta: a) O(n), razão 2; b) O(log n), ganha 1 passo; c) O(n²), razão 4;
// d) O(√n), razão √2 ≈ 1,41.

#include <stdio.h>

long misterio_a(int n) {
    long passos = 0;
    for (int i = 0; i < n; i += 3) {
        passos++;
    }
    return passos;
}

long misterio_b(int n) {
    long passos = 0;
    for (int i = n; i > 0; i /= 2) {
        passos++;
    }
    return passos;
}

long misterio_c(int n) {
    long passos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j += 2) {
            passos++;
        }
    }
    return passos;
}

long misterio_d(int n) {
    long passos = 0;
    for (int d = 0; d * d < n; d++) {
        passos++;
    }
    return passos;
}

void mostra(char nome, long p1, long p2) {
    printf("%c: %7ld -> %7ld  razão %.2f\n", nome, p1, p2, (double)p2 / p1);
}

int main(void) {
    mostra('a', misterio_a(1000), misterio_a(2000));
    mostra('b', misterio_b(1000), misterio_b(2000));
    mostra('c', misterio_c(1000), misterio_c(2000));
    mostra('d', misterio_d(1000), misterio_d(2000));
    return 0;
}
