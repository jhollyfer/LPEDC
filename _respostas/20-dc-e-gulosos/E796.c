// 0133 · Algoritmos gulosos
// Exercício E796 · ★★☆

#include <stdio.h>
#include <stdlib.h>

int decrescente(const void *a, const void *b) {
    int x = *(const int *)a;
    int y = *(const int *)b;
    return (x < y) - (x > y); // o maior vem primeiro
}

int troco_guloso(const int moedas[], int k, int valor) {
    int quantas = 0;
    int i = 0;
    printf("Troco de %d:", valor);
    while (valor > 0 && i < k) {
        if (moedas[i] <= valor) {
            printf(" %d", moedas[i]);
            valor -= moedas[i];
            quantas++;
        } else {
            i++;
        }
    }
    printf(" (%d moedas)\n", quantas);
    return quantas;
}

int main(void) {
    // as moedas chegaram do arquivo de configuração nesta ordem
    int moedas[] = {10, 50, 5, 100, 25};
    qsort(moedas, 5, sizeof moedas[0], decrescente);
    troco_guloso(moedas, 5, 190);
    troco_guloso(moedas, 5, 65);
    return 0;
}
