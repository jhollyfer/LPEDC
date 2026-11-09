// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2601 · ★☆☆ · Fiscal de dois em dois

#include <stdio.h>

int vagas_conferidas(int n) {
    int conta = 0;
    for (int i = 0; i < n; i += 2) {
        conta++;
    }
    return conta;
}

int main(void) {
    int ns[] = {10, 11, 1, 1000};
    for (int k = 0; k < 4; k++) {
        int n = ns[k];
        printf("n = %4d: %3d vagas, fórmula %3d\n", n, vagas_conferidas(n), (n + 1) / 2);
    }
    return 0;
}
