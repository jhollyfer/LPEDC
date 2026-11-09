// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2607 · ★☆☆ · A pilha do Euclides

#include <stdio.h>

int prof = 0;
int prof_max = 0;

long mdc(long a, long b) {
    prof++;
    if (prof > prof_max) {
        prof_max = prof;
    }
    long r = (b == 0) ? a : mdc(b, a % b);
    prof--;
    return r;
}

int main(void) {
    long pares[3][2] = {{84, 36}, {89, 55}, {1000000, 3}};
    for (int k = 0; k < 3; k++) {
        prof_max = 0;
        long m = mdc(pares[k][0], pares[k][1]);
        printf("mdc(%ld, %ld) = %ld, profundidade %d\n", pares[k][0], pares[k][1], m, prof_max);
    }
    return 0;
}
