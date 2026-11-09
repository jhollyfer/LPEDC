// 0168 · Complexidade espacial
// Exercício E1005 · ★★☆

#include <stdio.h>

#define MOD 1000000007L

int prof = 0;
int prof_max = 0;

// potência rápida: x^e = (x^(e/2))², vezes x se e for ímpar
long rapida(long x, long e) {
    prof++;
    if (prof > prof_max) {
        prof_max = prof;
    }
    long r;
    if (e == 0) {
        r = 1;
    } else {
        long meia = rapida(x, e / 2);
        r = meia * meia % MOD;
        if (e % 2 == 1) {
            r = r * x % MOD;
        }
    }
    prof--;
    return r;
}

int main(void) {
    long es[] = {10, 1000, 1000000, 1000000000};
    for (int i = 0; i < 4; i++) {
        prof_max = 0;
        long r = rapida(3, es[i]);
        printf("3^%ld mod p = %ld, profundidade %d\n", es[i], r, prof_max);
    }
    return 0;
}
