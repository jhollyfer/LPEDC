// A269 · Três critérios para a mesma carga

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    const char *nome;
    double peso, valor;
} Item;

int maior_valor(const void *a, const void *b) {
    const Item *x = a, *y = b;
    return (x->valor < y->valor) - (x->valor > y->valor);
}

int menor_peso(const void *a, const void *b) {
    const Item *x = a, *y = b;
    return (x->peso > y->peso) - (x->peso < y->peso);
}

int maior_razao(const void *a, const void *b) {
    const Item *x = a, *y = b;
    double rx = x->valor / x->peso, ry = y->valor / y->peso;
    return (rx < ry) - (rx > ry);
}

// o mesmo guloso da mochila fracionária, com o critério de ordem como parâmetro
double carrega(const Item itens[], int n, double cap,
               int (*criterio)(const void *, const void *)) {
    Item c[10];
    memcpy(c, itens, n * sizeof itens[0]); // não bagunça o vetor original
    qsort(c, n, sizeof c[0], criterio);
    double total = 0;
    for (int i = 0; i < n && cap > 0; i++) {
        double leva = c[i].peso <= cap ? c[i].peso : cap;
        total += c[i].valor * leva / c[i].peso;
        cap -= leva;
        printf(" %s %.0f", c[i].nome, leva);
    }
    printf("\n");
    return total;
}

int main(void) {
    // sucata a granel no ferro-velho; o carrinho leva 100 kg
    Item s[] = {
        {"cobre", 30, 1050}, {"alumínio", 50, 400}, {"latão", 25, 500},
        {"ferro", 120, 600}, {"fios", 10, 30},
    };
    int n = 5;

    printf("Maior valor primeiro:");
    double a = carrega(s, n, 100, maior_valor);
    printf("  R$ %.2f\n", a);
    printf("Menor peso primeiro:");
    double b = carrega(s, n, 100, menor_peso);
    printf("  R$ %.2f\n", b);
    printf("Maior R$/kg primeiro:");
    double c = carrega(s, n, 100, maior_razao);
    printf("  R$ %.2f\n", c);
    // o ferro tem o maior valor TOTAL, mas paga só R$ 5/kg: ocupa 70 kg que
    // renderiam muito mais com latão e alumínio
    return 0;
}
// Saída:
// Maior valor primeiro: cobre 30 ferro 70
//   R$ 1400.00
// Menor peso primeiro: fios 10 latão 25 cobre 30 alumínio 35
//   R$ 1860.00
// Maior R$/kg primeiro: cobre 30 latão 25 alumínio 45
//   R$ 1910.00
