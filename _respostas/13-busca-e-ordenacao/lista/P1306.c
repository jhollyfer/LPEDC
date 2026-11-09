// Lista · Módulo 13 · Busca e ordenação
// Exercício P1306 · ★☆☆ · Intercalando as filas de embarque

#include <stdio.h>

// junta a[0..na-1] e b[0..nb-1] (ordenados) em c; devolve as comparações
int intercala(const int a[], int na, const int b[], int nb, int c[]) {
    int i = 0, j = 0, k = 0, comparacoes = 0;
    while (i < na && j < nb) {
        comparacoes++;
        if (a[i] <= b[j]) {
            c[k++] = a[i++];
        } else {
            c[k++] = b[j++];
        }
    }
    while (i < na) {
        c[k++] = a[i++];
    }
    while (j < nb) {
        c[k++] = b[j++];
    }
    return comparacoes;
}

int main(void) {
    int portao_a[] = {4, 11, 18, 25, 30};
    int portao_b[] = {2, 9, 13};
    int fila[8];

    int comp = intercala(portao_a, 5, portao_b, 3, fila);
    printf("fila:");
    for (int k = 0; k < 8; k++) {
        printf(" %d", fila[k]);
    }
    printf("\ncomparações: %d\n", comp);
    return 0;
}
