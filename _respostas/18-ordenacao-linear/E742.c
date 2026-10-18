// 0124 · Juntando tudo
// Exercício E742 · ★★☆

#include <stdio.h>
#include <stdlib.h>
#include "pix.h"

#define N 1000000

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

// quickselect com pivô do meio sobre um vetor de int
int seleciona(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        troca(&v[p + (r - p) / 2], &v[r]);
        int pivo = v[r], j = p;
        for (int i = p; i < r; i++) {
            if (v[i] <= pivo) {
                troca(&v[j], &v[i]);
                j++;
            }
        }
        troca(&v[j], &v[r]);
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

void mostra(const char *rotulo, int centavos) {
    printf("%s R$ %d,%02d\n", rotulo, centavos / 100, centavos % 100);
}

int main(void) {
    Pix *v = malloc(N * sizeof(Pix));
    Pix *aux = malloc(N * sizeof(Pix));
    int *valores = malloc(N * sizeof(int));  // 4 MB em vez de 12: só a chave
    if (v == NULL || aux == NULL || valores == NULL) {
        free(v);
        free(aux);
        free(valores);
        return 1;
    }
    pix_gera(v, N, 2024);
    for (int i = 0; i < N; i++) {
        valores[i] = v[i].centavos;
    }

    int k50 = N / 2, k99 = (99 * (N / 100)) - 1; // posto mais próximo
    int mediana = seleciona(valores, N, k50);
    int p99 = seleciona(valores, N, k99);
    mostra("mediana:", mediana);
    mostra("p99:    ", p99);

    pix_por_valor(v, aux, N);
    printf("conferindo com o radix: %s\n",
           v[k50].centavos == mediana && v[k99].centavos == p99 ? "iguais" : "diferentes");
    free(v);
    free(aux);
    free(valores);
    return 0;
}
