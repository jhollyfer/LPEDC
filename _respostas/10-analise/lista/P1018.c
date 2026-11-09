// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1018 · ★★☆ · Euclides, o invariante e o pior caso

#include <assert.h>
#include <stdio.h>

int mdc_lento(int a, int b) {
    if (b == 0) {
        return a;
    }
    if (a == 0) {
        return b;
    }
    for (int d = a < b ? a : b; d > 1; d--) {
        if (a % d == 0 && b % d == 0) {
            return d;
        }
    }
    return 1;
}

int mdc(int a, int b, int *passos) {
    int g = mdc_lento(a, b);
    *passos = 0;
    while (b != 0) {
        assert(mdc_lento(a, b) == g); // invariante
        int r = a % b;
        (*passos)++;
        a = b;
        b = r;
    }
    assert(a == g); // término: mdc(a, 0) = a
    return a;
}

int main(void) {
    int pares[3][2] = {{1071, 462}, {89, 55}, {100, 75}};
    for (int k = 0; k < 3; k++) {
        int passos;
        int g = mdc(pares[k][0], pares[k][1], &passos);
        printf("mdc(%d, %d) = %d em %d passos\n", pares[k][0], pares[k][1], g, passos);
    }
    return 0;
}
