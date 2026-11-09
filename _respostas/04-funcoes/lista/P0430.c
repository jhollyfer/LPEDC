// Lista · Módulo 04 · Funções e modularização
// Exercício P0430 · ★★★ · A fatoração em primos

#include <stdio.h>

int expoente(int n, int d) {
    if (n % d != 0) {
        return 0;
    }
    return 1 + expoente(n / d, d);
}

int sem_fator(int n, int d) {
    if (n % d != 0) {
        return n;
    }
    return sem_fator(n / d, d);
}

void fatorar(int n, int d) {
    if (n == 1) {
        return;
    }
    if (d * d > n) {
        printf("%d", n); // o que sobrou é primo
        return;
    }
    if (n % d != 0) {
        fatorar(n, d + 1);
        return;
    }
    int e = expoente(n, d);
    if (e > 1) {
        printf("%d^%d", d, e);
    } else {
        printf("%d", d);
    }
    int resto = sem_fator(n, d);
    if (resto > 1) {
        printf(" x ");
    }
    fatorar(resto, d + 1);
}

void mostrar(int n) {
    printf("%d = ", n);
    fatorar(n, 2);
    printf("\n");
}

int main(void) {
    mostrar(360);
    mostrar(2026);
    mostrar(1024);
    mostrar(9973);
    return 0;
}
