// 0166 · O, Ω e Θ de verdade
// Exercício E992 · ★☆☆

#include <stdio.h>

#define LIMITE 10000

// comparações para montar as duplas do campeonato de n jogadores
long custo(long n) {
    return n * n - 6 * n;
}

// menor n0 com custo(n) >= c * n² para todo n de n0 até LIMITE
long acha_n0(double c) {
    long n0 = 1;
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) < c * n * n) {
            n0 = n + 1;
        }
    }
    return n0;
}

int main(void) {
    double cs[] = {0.5, 0.9, 1.0};
    for (int i = 0; i < 3; i++) {
        long n0 = acha_n0(cs[i]);
        if (n0 > LIMITE) {
            printf("c = %.1f: nenhum n0 até %d\n", cs[i], LIMITE);
        } else {
            printf("c = %.1f: n0 = %ld\n", cs[i], n0);
        }
    }
    return 0;
}
