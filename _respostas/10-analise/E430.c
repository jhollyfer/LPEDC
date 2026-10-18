// 0072 · Notação O: como o custo cresce
// Exercício E430 · ★★☆

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

const char *classe(double razao) {
    if (razao < 1.2) {
        return "O(log n)";
    }
    if (razao < 1.7) {
        return "O(raiz n)";
    }
    if (razao < 3) {
        return "O(n)";
    }
    return "O(n^2)";
}

void mostra(char nome, long p1, long p2) {
    double razao = (double)p2 / p1;
    printf("%c: %7ld -> %7ld  razão %.2f  %s\n", nome, p1, p2, razao, classe(razao));
}

int main(void) {
    mostra('a', misterio_a(1000), misterio_a(2000));
    mostra('b', misterio_b(1000), misterio_b(2000));
    mostra('c', misterio_c(1000), misterio_c(2000));
    mostra('d', misterio_d(1000), misterio_d(2000));
    return 0;
}
