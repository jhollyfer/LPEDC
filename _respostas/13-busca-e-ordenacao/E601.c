// 0101 · Comparando: estabilidade, custo e qsort
// Exercício E601 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

// decrescente: o MAIOR vem antes
int compara_desc(const void *a, const void *b) {
    double x = *(const double *) a;
    double y = *(const double *) b;
    return (x < y) - (x > y);
}

int main(void) {
    double gasolina[] = {5.89, 6.19, 5.79, 6.05, 5.99, 6.29};
    size_t n = sizeof gasolina / sizeof gasolina[0];

    qsort(gasolina, n, sizeof gasolina[0], compara_desc);
    for (size_t i = 0; i < n; i++) {
        printf("R$ %.2f\n", gasolina[i]);
    }
    return 0;
}
