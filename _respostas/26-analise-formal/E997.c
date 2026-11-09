// 0167 · Somatórios que saem de laços
// Exercício E997 · ★☆☆

#include <stdio.h>

int main(void) {
    long n = 365;
    long cofre = 0;
    for (long dia = 1; dia <= n; dia++) {
        cofre += dia;                    // no dia d, guarda d reais
    }
    printf("pelo laço:    R$ %ld\n", cofre);
    printf("pela fórmula: R$ %ld\n", n * (n + 1) / 2);
    return 0;
}
