// A247 · Os maiores Pix do dia, sem ordenar o dia

#include <stdio.h>
#include <stdlib.h>
#include "pix.h"

#define N 1000000
#define TOP 5

void troca(Pix *a, Pix *b) {
    Pix aux = *a;
    *a = *b;
    *b = aux;
}

// quickselect pelo valor, com pivô do meio (os dados não vêm ordenados,
// mas o pivô do meio custa nada e protege do caso ordenado)
void seleciona(Pix v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        troca(&v[p + (r - p) / 2], &v[r]);
        int pivo = v[r].centavos, j = p;
        for (int i = p; i < r; i++) {
            if (v[i].centavos <= pivo) {
                troca(&v[j], &v[i]);
                j++;
            }
        }
        troca(&v[j], &v[r]);
        if (j == k) {
            return;
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
}

int main(void) {
    Pix *v = malloc(N * sizeof(Pix));
    if (v == NULL) {
        return 1;
    }
    pix_gera(v, N, 2024);

    seleciona(v, N, N / 2);
    printf("valor mediano: R$ %d,%02d\n", v[N / 2].centavos / 100, v[N / 2].centavos % 100);

    // os TOP maiores ficam em v[N-TOP..N-1]; só eles precisam de ordem
    seleciona(v, N, N - TOP);
    qsort(v + N - TOP, TOP, sizeof(Pix), pix_compara_valor);
    printf("os %d maiores do dia:\n", TOP);
    for (int i = N - 1; i >= N - TOP; i--) {
        pix_mostra(&v[i]);
    }
    free(v);
    return 0;
}
// Saída:
// valor mediano: R$ 56,98
// os 5 maiores do dia:
// #0323438 02:04:16 R$    9999,90
// #0698564 18:19:13 R$    9999,85
// #0090794 01:05:26 R$    9999,61
// #0331073 07:40:47 R$    9999,58
// #0324779 17:16:28 R$    9999,55
//
// Duas seleções e um qsort de 5 elementos, em vez de ordenar 1 milhão. O
// valor mediano (R$ 56,98) é bem menor que a média, puxada pelos poucos Pix
// grandes. Repare que pix_compara_valor, feita para o qsort do vetor
// inteiro, serve igual para ordenar só o pedaço v + N - TOP.
