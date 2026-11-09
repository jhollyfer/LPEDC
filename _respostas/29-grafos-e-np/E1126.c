// 0188 · Aproximação
// Exercício E1126 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 16
#define CAPACIDADE 10

int compara_desc(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x < y) - (x > y);
}

int first_fit(const int carga[], int n) {
    int livre[MAX], viagens = 0;
    for (int i = 0; i < n; i++) {
        int v = 0;
        while (v < viagens && livre[v] < carga[i]) v++;
        if (v == viagens) livre[viagens++] = CAPACIDADE;
        livre[v] -= carga[i];
    }
    return viagens;
}

void compara(const char *nome, const int carga[], int n) {
    int copia[MAX], total = 0;
    memcpy(copia, carga, n * sizeof carga[0]);
    qsort(copia, n, sizeof copia[0], compara_desc);
    for (int i = 0; i < n; i++) total += carga[i];
    printf("%s: FF %d, FFD %d, limite %d\n", nome, first_fit(carga, n), first_fit(copia, n),
           (total + CAPACIDADE - 1) / CAPACIDADE);
}

int main(void) {
    int l1[] = {4, 4, 6, 9, 2, 6, 7, 7};
    int l2[] = {2, 2, 2, 2, 2, 2, 7, 7, 7, 7, 7, 7};
    int l3[] = {3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 4, 5};
    compara("Lista 1", l1, 8);
    compara("Lista 2", l2, 12);
    compara("Lista 3", l3, 13);
    return 0;
}
