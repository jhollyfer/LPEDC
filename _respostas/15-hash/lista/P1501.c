// Lista · Módulo 15 · Tabelas hash
// Exercício P1501 · ★☆☆ · Cem baldes ou noventa e sete?

#include <stdio.h>

void distribui(const int chaves[], int n, int m) {
    int conta[100] = {0};
    for (int i = 0; i < n; i++) {
        conta[chaves[i] % m]++;
    }
    int usados = 0, colisoes = 0;
    for (int b = 0; b < m; b++) {
        if (conta[b] > 0) {
            usados++;
            colisoes += conta[b] - 1; // quem chegou depois do primeiro colidiu
        }
    }
    printf("m = %d: baldes usados %d, colisões %d\n", m, usados, colisoes);
    for (int i = 0; i < n; i++) {
        printf("  %d -> %d\n", chaves[i], chaves[i] % m);
    }
}

int main(void) {
    // os pedidos da loja online terminam todos em 50 ou 00
    int pedidos[] = {31250, 48700, 52150, 61900, 77350, 80200, 93450, 15600};
    int n = 8;

    distribui(pedidos, n, 100);
    distribui(pedidos, n, 97);
    return 0;
}
