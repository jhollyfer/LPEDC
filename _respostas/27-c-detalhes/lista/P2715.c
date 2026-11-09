// Lista · Módulo 27 · Detalhes de C que caem em prova
// Exercício P2715 · ★★☆ · O inverno em Gramado

#include <stdio.h>

double media(const int *v, unsigned n) {
    int soma = 0;
    for (unsigned i = 0; i < n; i++) {
        soma += v[i];
    }
    return (double)soma / n; // double com unsigned: tudo vira double
}

int compara(unsigned a, unsigned b) {
    if (a > b) {
        return 1;
    }
    return a < b ? -1 : 0;
}

int main(void) {
    int temperaturas[] = {-3, 2, -5, -2};
    printf("média: %.2f\n", media(temperaturas, 4));
    printf("compara(3, 7) = %d\n", compara(3, 7));
    printf("compara(7, 3) = %d\n", compara(7, 3));
    printf("compara(5, 5) = %d\n", compara(5, 5));
    return 0;
}
