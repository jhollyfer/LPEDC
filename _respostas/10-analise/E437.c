// 0073 · Invariantes de laço e corretude
// Exercício E437 · ★★★
//
// Resposta: lg(1) = 0, lg(10) = 3, lg(1000) = 9, lg(1024) = 10,
// lg(100000) = 16 e nenhuma divergência.

#include <math.h>
#include <stdio.h>

// Recebe n >= 1; devolve o maior i tal que 2 elevado a i <= n.
int lg(int n) {
    int i = 0;
    int m = n;
    while (m > 1) {
        // invariante: (2^i) * m <= n < (2^i) * (m + 1)
        m = m / 2;
        i++;
    }
    // m == 1: 2^i <= n < 2^(i+1). Parada: m cai pela metade a cada volta.
    return i;
}

int main(void) {
    int testes[5] = {1, 10, 1000, 1024, 100000};

    for (int k = 0; k < 5; k++) {
        printf("lg(%d) = %d\n", testes[k], lg(testes[k]));
    }

    int divergencias = 0;
    for (int n = 1; n <= 100000; n++) {
        if (lg(n) != (int)floor(log2(n))) {
            divergencias++;
        }
    }
    printf("divergências de 1 a 100000: %d\n", divergencias);
    return 0;
}
