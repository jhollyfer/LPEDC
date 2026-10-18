// 0135 · Mochila fracionária
// Exercício E807 · ★★☆

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    const char *fruta;
    double kg, valor;
} Caixa;

int por_razao(const void *a, const void *b) {
    const Caixa *x = a;
    const Caixa *y = b;
    double rx = x->valor / x->kg;
    double ry = y->valor / y->kg;
    return (rx < ry) - (rx > ry); // sem cortar a parte fracionária
}

int main(void) {
    Caixa c[] = {{"uva", 10, 42}, {"caqui", 10, 20}, {"ameixa", 10, 48}};
    int n = 3;
    double livre = 15, total = 0;

    qsort(c, n, sizeof c[0], por_razao);
    for (int i = 0; i < n && livre > 0; i++) {
        double leva = c[i].kg <= livre ? c[i].kg : livre;
        total += c[i].valor * leva / c[i].kg;
        printf("%.0f kg de %s\n", leva, c[i].fruta);
        livre -= leva;
    }
    printf("Total: R$ %.2f\n", total);
    return 0;
}
