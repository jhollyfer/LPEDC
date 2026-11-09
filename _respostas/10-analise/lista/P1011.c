// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1011 · ★★☆ · Achar a fórmula exata de T(n)

#include <stdbool.h>
#include <stdio.h>

long conta(int n) {
    long passos = 0;
    for (int i = 0; i < n; i += 2) {
        for (int j = i; j < n; j++) {
            passos++;
        }
    }
    return passos;
}

long formula(int n) {
    return (long) ((n + 1) / 2) * ((n + 2) / 2);
}

int main(void) {
    for (int n = 1; n <= 6; n++) {
        printf("T(%d) = %ld\n", n, conta(n));
    }
    bool ok = true;
    for (int n = 1; n <= 1000; n++) {
        if (formula(n) != conta(n)) {
            ok = false;
        }
    }
    printf("Fórmula confere de 1 a 1000: %s\n", ok ? "sim" : "não");
    return 0;
}
