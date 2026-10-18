// 0099 · Merge sort
// Exercício E592 · ★★☆
//
// Com "<" no lugar de "<=", a saída vira:
//   Eva 20, Davi 30, Bruno 30, Carla 50, Ana 50
// No empate, a intercalação passa a pegar o da DIREITA primeiro, e os
// empatados saem na ordem inversa da chegada: o merge sort deixa de ser estável.

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    char cliente[8];
    int valor;
} Pedido;

void intercala(Pedido v[], Pedido w[], int p, int q, int r) {
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i].valor <= v[j].valor) {
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

void merge_sort(Pedido v[], Pedido w[], int p, int r) {
    if (r - p < 2) {
        return;
    }
    int q = p + (r - p) / 2;
    merge_sort(v, w, p, q);
    merge_sort(v, w, q, r);
    intercala(v, w, p, q, r);
}

int main(void) {
    Pedido fila[] = {{"Ana", 50}, {"Bruno", 30}, {"Carla", 50}, {"Davi", 30}, {"Eva", 20}};
    int n = 5;
    Pedido *w = malloc(n * sizeof *w);
    if (w == NULL) {
        return 1;
    }
    merge_sort(fila, w, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%s %d%s", fila[i].cliente, fila[i].valor, i < n - 1 ? ", " : "\n");
    }
    free(w);
    return 0;
}
