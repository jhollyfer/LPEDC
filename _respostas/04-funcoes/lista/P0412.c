// Lista · Módulo 04 · Funções e modularização
// Exercício P0412 · ★★☆ · Três linhas de ônibus no terminal

#include <stdio.h>

int mdc(int a, int b) {
    if (b == 0) {
        return a;
    }
    return mdc(b, a % b);
}

int mmc(int a, int b) {
    return a / mdc(a, b) * b;
}

int main(void) {
    int juntas = mmc(mmc(12, 18), 30);
    int saida = 6 * 60 + juntas;

    printf("mdc(12, 18) = %d\n", mdc(12, 18));
    printf("mmc(12, 18) = %d\n", mmc(12, 18));
    printf("As três saem juntas a cada %d minutos\n", juntas);
    printf("Próxima saída juntas: %02d:%02d\n", saida / 60, saida % 60);
    return 0;
}
