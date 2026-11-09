// Lista · Módulo 04 · Funções e modularização
// Exercício P0424 · ★★★ · Goldbach nos anos pares

#include <stdbool.h>
#include <stdio.h>

bool eh_primo(int n) {
    if (n < 2) {
        return false;
    }
    for (int d = 2; d * d <= n; d++) {
        if (n % d == 0) {
            return false;
        }
    }
    return true;
}

int menor_parcela(int n) {
    for (int p = 2; p <= n / 2; p++) {
        if (eh_primo(p) && eh_primo(n - p)) {
            return p;
        }
    }
    return 0; // seria um contraexemplo de Goldbach
}

int formas(int n) {
    int total = 0;
    for (int p = 2; p <= n / 2; p++) {
        if (eh_primo(p) && eh_primo(n - p)) {
            total++;
        }
    }
    return total;
}

int main(void) {
    for (int ano = 2020; ano <= 2030; ano += 2) {
        int p = menor_parcela(ano);
        printf("%d = %d + %d\n", ano, p, ano - p);
    }
    printf("2026 pode ser escrito de %d formas\n", formas(2026));
    return 0;
}
