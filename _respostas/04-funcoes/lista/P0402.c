// Lista · Módulo 04 · Funções e modularização
// Exercício P0402 · ★☆☆ · O artilheiro do campeonato

#include <stdio.h>

int maior(int a, int b) {
    return a > b ? a : b;
}

int main(void) {
    int duda = 12, leo = 17, bia = 15;

    printf("Gols: %d, %d e %d\n", duda, leo, bia);
    printf("Artilheiro com %d gols\n", maior(maior(duda, leo), bia));
    return 0;
}
