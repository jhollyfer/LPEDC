// 0123 · Quickselect
// Exercício E733 · ★☆☆

#include <stdio.h>

#define MAX 100

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        if (j == k) {
            return v[j];
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
    return v[p];
}

// roda o quickselect numa cópia: o vetor original não sai do lugar
int seleciona_copia(const int v[], int n, int k) {
    int copia[MAX];
    for (int i = 0; i < n; i++) {
        copia[i] = v[i];
    }
    return quickselect(copia, n, k);
}

int main(void) {
    // redação do simulado: notas de 11 alunos
    int notas[] = {720, 480, 860, 640, 920, 560, 700, 380, 800, 600, 680};
    int n = 11;

    printf("menor:       %d\n", seleciona_copia(notas, n, 0));
    printf("2ª menor:    %d\n", seleciona_copia(notas, n, 1));
    printf("mediana:     %d\n", seleciona_copia(notas, n, n / 2));
    printf("2ª maior:    %d\n", seleciona_copia(notas, n, n - 2));
    printf("maior:       %d\n", seleciona_copia(notas, n, n - 1));
    printf("primeira do vetor continua: %d\n", notas[0]);
    return 0;
}
