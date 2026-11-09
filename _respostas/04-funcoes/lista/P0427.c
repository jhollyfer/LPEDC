// Lista · Módulo 04 · Funções e modularização
// Exercício P0427 · ★★★ · As marcas da régua

#include <stdio.h>

int chamadas = 0;

void marca(int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("-");
    }
    printf("\n");
}

void regua(int n) {
    chamadas++;
    if (n == 0) {
        return;
    }
    regua(n - 1);
    marca(n);
    regua(n - 1);
}

int main(void) {
    regua(4);
    printf("Chamadas de regua: %d\n", chamadas);
    return 0;
}
