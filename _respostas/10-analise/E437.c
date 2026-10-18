// 0073 · Invariantes de laço e corretude
// Exercício E437 · ★★★

#include <assert.h>
#include <math.h>
#include <stdio.h>

// Recebe n >= 1; devolve o maior i tal que 2 elevado a i <= n.
int lg(int n) {
    int i = 0;
    int m = n;
    long p = 1; // p == 2 elevado a i
    while (m > 1) {
        // invariante: p * m <= n < p * (m + 1)
        assert(p * m <= n && n < p * (m + 1));
        m = m / 2;
        i++;
        p = p * 2;
    }
    // término: m == 1, então 2^i <= n < 2^(i+1)
    assert(m == 1 && p <= n && n < 2 * p);
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
