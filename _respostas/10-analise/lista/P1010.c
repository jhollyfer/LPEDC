// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1010 · ★☆☆ · Os apertos de mão da reunião

#include <stdio.h>

long apertos_laco(int n) {
    long cont = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            cont++;
        }
    }
    return cont;
}

long apertos_formula(int n) {
    return (long) n * (n - 1) / 2;
}

int main(void) {
    int testes[4] = {5, 10, 50, 1000};
    for (int i = 0; i < 4; i++) {
        long a = apertos_laco(testes[i]);
        long b = apertos_formula(testes[i]);
        printf("n = %d: laço %ld, fórmula %ld, %s\n", testes[i], a, b, a == b ? "confere" : "NÃO confere");
    }
    return 0;
}
