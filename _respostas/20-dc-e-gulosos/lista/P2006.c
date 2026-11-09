// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2006 · ★☆☆ · O barco de Parintins

#include <stdio.h>
#include <stdlib.h>

#define N 5
#define CAP 500.0

typedef struct {
    const char *nome;
    double kg, valor;
} Produto;

int compara(const void *a, const void *b) {
    const Produto *x = a, *y = b;
    double rx = x->valor / x->kg, ry = y->valor / y->kg;
    if (rx > ry) {
        return -1;
    }
    if (rx < ry) {
        return 1;
    }
    return 0;
}

int main(void) {
    Produto p[N] = {
        {"castanha", 200, 3000}, {"farinha", 300, 1500}, {"guaraná", 100, 2500},
        {"pirarucu", 150, 4200}, {"cupuaçu", 250, 2000},
    };
    qsort(p, N, sizeof p[0], compara);
    double livre = CAP, total = 0;
    for (int i = 0; i < N && livre > 0; i++) {
        double leva = p[i].kg <= livre ? p[i].kg : livre;
        double ganho = p[i].valor * leva / p[i].kg;
        printf("%s: %.0f kg, R$ %.2f\n", p[i].nome, leva, ganho);
        livre -= leva;
        total += ganho;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
