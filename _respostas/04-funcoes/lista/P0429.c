// Lista · Módulo 04 · Funções e modularização
// Exercício P0429 · ★★★ · Os números felizes

#include <stdbool.h>
#include <stdio.h>

int soma_quadrados(int n) {
    if (n == 0) {
        return 0;
    }
    int d = n % 10;
    return d * d + soma_quadrados(n / 10);
}

bool feliz(int n) {
    if (n == 1) {
        return true;
    }
    if (n == 4) {
        return false; // entrou no ciclo
    }
    return feliz(soma_quadrados(n));
}

void caminho(int n) {
    printf("%d", n);
    if (n == 1 || n == 4) {
        printf("\n");
        return;
    }
    printf(" -> ");
    caminho(soma_quadrados(n));
}

int main(void) {
    caminho(2026);

    int total = 0;
    printf("Felizes até 50:");
    for (int n = 1; n <= 50; n++) {
        if (feliz(n)) {
            printf(" %d", n);
            total++;
        }
    }
    printf("\nTotal: %d\n", total);
    return 0;
}
