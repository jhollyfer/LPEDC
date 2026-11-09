// Lista · Módulo 06 · Ponteiros
// Exercício P0606 · ★☆☆ · O pódio do campeonato

#include <stdio.h>
#include <stdlib.h>

int decrescente(const void *a, const void *b) {
    int x = *(const int *) a;
    int y = *(const int *) b;
    return (x < y) - (x > y); // negativo se x > y: x vem antes
}

int main(void) {
    int pontos[8] = {21, 34, 18, 29, 34, 12, 25, 30};
    int n = sizeof pontos / sizeof pontos[0];

    qsort(pontos, n, sizeof pontos[0], decrescente);
    printf("Tabela:");
    for (int i = 0; i < n; i++) {
        printf(" %d", pontos[i]);
    }
    printf("\n");
    printf("1º: %d pontos\n2º: %d pontos\n3º: %d pontos\n", pontos[0], pontos[1], pontos[2]);
    return 0;
}
