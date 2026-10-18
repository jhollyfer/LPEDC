// 0094 · Merge sort
// Exercício E562 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct {
    char cliente[8];
    int valor;
} Pedido;

void intercala(Pedido v[], Pedido w[], int p, int q, int r, bool estavel) {
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        // com <=, no empate sai primeiro o da esquerda (quem chegou antes)
        bool pega_esquerda = estavel ? v[i].valor <= v[j].valor
                                     : v[i].valor < v[j].valor;
        if (pega_esquerda) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }
    while (i < q) {
        w[k++] = v[i++];
    }
    while (j < r) {
        w[k++] = v[j++];
    }
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
}

void merge_sort(Pedido v[], Pedido w[], int p, int r, bool estavel) {
    if (r - p < 2) {
        return;
    }
    int q = p + (r - p) / 2;
    merge_sort(v, w, p, q, estavel);
    merge_sort(v, w, q, r, estavel);
    intercala(v, w, p, q, r, estavel);
}

void mostra(const char *rotulo, const Pedido v[], int n) {
    printf("%s", rotulo);
    for (int i = 0; i < n; i++) {
        printf("%s %d%s", v[i].cliente, v[i].valor, i < n - 1 ? ", " : "\n");
    }
}

int main(void) {
    Pedido fila[] = {{"Ana", 50}, {"Bruno", 30}, {"Carla", 50}, {"Davi", 30}, {"Eva", 20}};
    Pedido copia[] = {{"Ana", 50}, {"Bruno", 30}, {"Carla", 50}, {"Davi", 30}, {"Eva", 20}};
    int n = 5;
    Pedido *w = malloc(n * sizeof *w);
    if (w == NULL) {
        return 1;
    }
    merge_sort(fila, w, 0, n, true);
    merge_sort(copia, w, 0, n, false);
    mostra("com <=: ", fila, n);
    mostra("com <:  ", copia, n);
    free(w);
    return 0;
}
