// 0170 · Precedência e ordem de avaliação
// Exercício E1019 · ★★★

#include <stdio.h>

#define DOBRO(x) ((x) + (x))
#define AREA(l, c) ((l) * (c))

int maior(int a, int b) {
    return a > b ? a : b; // cada argumento já chega avaliado, uma vez só
}

int main(void) {
    int n = 5;
    printf("100 / DOBRO(5) = %d\n", 100 / DOBRO(n));
    printf("AREA(2 + 1, 4) = %d\n", AREA(2 + 1, 4));

    int fila = 3, limite = 2;
    int m = maior(fila++, limite);
    printf("maior = %d, fila = %d\n", m, fila);
    return 0;
}
