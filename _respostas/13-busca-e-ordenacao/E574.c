// 0096 · Comparando: estabilidade, custo e qsort
// Exercício E574 · ★★☆

#include <stdio.h>
#include <stdlib.h>

// x - y estoura o int quando os sinais são opostos e os valores são grandes
int compara(const void *a, const void *b) {
    int x = *(const int *) a;
    int y = *(const int *) b;
    return (x > y) - (x < y);
}

int main(void) {
    int saldos[] = {2000000000, -1500000000, 15, -7, 1000000000};
    size_t n = sizeof saldos / sizeof saldos[0];

    qsort(saldos, n, sizeof saldos[0], compara);
    for (size_t i = 0; i < n; i++) {
        printf("%d\n", saldos[i]);
    }
    return 0;
}
