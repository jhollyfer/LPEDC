// Lista · Módulo 19 · Enumeração e backtracking
// Exercício P1910 · ★☆☆ · Três dígitos que somam 15

#include <stdio.h>

#define K 3
#define ALVO 15

int dig[K];
int total = 0;

void escolhe(int menor, int k, int soma) {
    if (k == K) {
        if (soma == ALVO) {
            total++;
            printf("%d %d %d\n", dig[0], dig[1], dig[2]);
        }
        return;
    }
    for (int d = menor; d <= 9; d++) {
        if (soma + d > ALVO) {
            break;
        }
        dig[k] = d;
        escolhe(d + 1, k + 1, soma + d);
    }
}

int main(void) {
    escolhe(1, 0, 0);
    printf("Total: %d trincas\n", total);
    return 0;
}
