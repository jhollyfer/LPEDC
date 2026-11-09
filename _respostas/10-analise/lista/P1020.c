// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1020 · ★★☆ · As duplas da gincana em O(n)

#include <stdio.h>

long duplas_lento(const int v[], int n, long *passos) {
    long cont = 0;
    *passos = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            (*passos)++;
            if ((v[i] + v[j]) % 2 == 0) {
                cont++;
            }
        }
    }
    return cont;
}

long duplas_rapido(const int v[], int n, long *passos) {
    long p = 0, q = 0;
    *passos = 0;
    for (int i = 0; i < n; i++) {
        (*passos)++;
        if (v[i] % 2 == 0) {
            p++;
        } else {
            q++;
        }
    }
    return p * (p - 1) / 2 + q * (q - 1) / 2;
}

int main(void) {
    int idades[8] = {3, 8, 5, 12, 7, 10, 1, 4};
    long pl, pr;
    long a = duplas_lento(idades, 8, &pl);
    long b = duplas_rapido(idades, 8, &pr);
    printf("Lento: %ld duplas em %ld passos\n", a, pl);
    printf("Rápido: %ld duplas em %ld passos\n", b, pr);
    return 0;
}
