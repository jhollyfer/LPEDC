// 0133 · Algoritmos gulosos
// Exercício E793 · ★☆☆

#include <stdio.h>

void saque(int valor) {
    int notas[] = {200, 100, 50, 20, 10, 5, 2};
    int total = 0;
    printf("Saque de R$ %d:\n", valor);
    for (int i = 0; i < 7; i++) {
        int q = 0;
        while (notas[i] <= valor) {
            valor -= notas[i];
            q++;
        }
        if (q > 0) {
            printf("  %d de R$ %d\n", q, notas[i]);
            total += q;
        }
    }
    printf("  total: %d notas\n", total);
}

int main(void) {
    saque(380);
    saque(1270);
    return 0;
}
