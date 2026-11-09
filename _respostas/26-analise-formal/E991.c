// 0166 · O, Ω e Θ de verdade
// Exercício E991 · ★☆☆

#include <stdio.h>

#define LIMITE 10000

// passos para gerar os boletos de n condôminos
long custo(long n) {
    return 5 * n + 40;
}

// menor n0 com custo(n) <= c * n para todo n de n0 até LIMITE
long acha_n0(long c) {
    long n0 = 1;
    for (long n = 1; n <= LIMITE; n++) {
        if (custo(n) > c * n) {
            n0 = n + 1;
        }
    }
    return n0;
}

int main(void) {
    long cs[] = {6, 7, 10, 45};
    for (int i = 0; i < 4; i++) {
        printf("c = %2ld: n0 = %ld\n", cs[i], acha_n0(cs[i]));
    }
    return 0;
}
