// Lista · Módulo 13 · Busca e ordenação
// Exercício P1317 · ★★☆ · O merge sort mostrando cada intercalação

#include <stdio.h>

int v[] = {38, 27, 43, 3, 9, 82, 10};
int aux[7];

void intercala(int p, int q, int r) {
    int i = p, j = q + 1, k = p;
    while (i <= q && j <= r) {
        aux[k++] = (v[i] <= v[j]) ? v[i++] : v[j++];
    }
    while (i <= q) {
        aux[k++] = v[i++];
    }
    while (j <= r) {
        aux[k++] = v[j++];
    }
    for (k = p; k <= r; k++) {
        v[k] = aux[k];
    }
    printf("intercala [%d..%d]:", p, r);
    for (k = p; k <= r; k++) {
        printf(" %d", v[k]);
    }
    printf("\n");
}

void merge_sort(int p, int r) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(p, q);
        merge_sort(q + 1, r);
        intercala(p, q, r);
    }
}

int main(void) {
    merge_sort(0, 6);
    return 0;
}
