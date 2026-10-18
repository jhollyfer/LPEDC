// 0132 · Inversões e subvetor de soma máxima
// Exercício E788 · ★☆☆

#include <stdio.h>

int intercala(int v[], int w[], int p, int q, int r) {
    int inv = 0;
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            inv += q - i; // v[j] passa na frente de todos os que sobram à esquerda
            w[k++] = v[j++];
        }
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
    return inv;
}

int conta(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;
    }
    int q = p + (r - p) / 2;
    return conta(v, w, p, q) + conta(v, w, q, r) + intercala(v, w, p, q, r);
}

int main(void) {
    // posição de cada candidato na prova, na ordem em que entregaram
    int pos[] = {6, 2, 8, 4, 1, 7, 3, 5};
    int w[8];
    int total = conta(pos, w, 0, 8);
    printf("Inversões: %d\n", total);
    printf("Ordenado:");
    for (int i = 0; i < 8; i++) {
        printf(" %d", pos[i]);
    }
    printf("\n");
    return 0;
}
