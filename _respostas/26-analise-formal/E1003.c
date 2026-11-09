// 0168 · Complexidade espacial
// Exercício E1003 · ★☆☆

#include <stdio.h>

int prof = 0;
int prof_max = 0;

// base elevada a e, uma multiplicação por chamada: T(e) = T(e-1) + 1
long potencia(long base, int e) {
    prof++;
    if (prof > prof_max) {
        prof_max = prof;
    }
    long r = (e == 0) ? 1 : base * potencia(base, e - 1);
    prof--;
    return r;
}

int main(void) {
    for (int e = 10; e <= 30; e += 10) {
        prof_max = 0;
        long p = potencia(3, e);
        printf("3^%d = %ld, profundidade %d\n", e, p, prof_max);
    }
    return 0;
}
