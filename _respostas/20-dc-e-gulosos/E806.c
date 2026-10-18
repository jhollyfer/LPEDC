// 0135 · Mochila fracionária
// Exercício E806 · ★☆☆

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *nome;
    double peso, valor;
} Tempero;

int por_razao(const void *a, const void *b) {
    const Tempero *x = a;
    const Tempero *y = b;
    double rx = x->valor / x->peso;
    double ry = y->valor / y->peso;
    return (rx < ry) - (rx > ry); // o de maior R$/kg vem primeiro
}

int main(void) {
    Tempero t[] = {{"canela", 4, 120}, {"pimenta", 6, 240}, {"orégano", 5, 100}, {"cominho", 3, 75}};
    int n = 4;
    double livre = 12, total = 0;

    qsort(t, n, sizeof t[0], por_razao);
    for (int i = 0; i < n && livre > 0; i++) {
        double leva = t[i].peso <= livre ? t[i].peso : livre;
        total += t[i].valor * leva / t[i].peso;
        printf("%.0f de %.0f kg: %s\n", leva, t[i].peso, t[i].nome);
        livre -= leva;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
