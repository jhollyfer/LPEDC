// 0103 · Heapsort
// Exercício E617 · ★★★
//
// Resposta: a fase 1 descia os pais de cima para baixo (0, 1, 2). O desce só
// funciona quando as duas subárvores já são heaps. De cima para baixo, a
// raiz desce antes de os filhos estarem arrumados, e o vetor termina como
// [3 5 7 4 2 6 1], que não é heap. Do último pai até a raiz, cada pai desce
// sobre subárvores já arrumadas.

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && v[f + 1] > v[f]) {
            f++;
        }
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void heapsort(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) { // de baixo para cima
        desce(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
    }
}

int main(void) {
    int tempos[] = {1, 2, 3, 4, 5, 6, 7};
    heapsort(tempos, 7);
    for (int i = 0; i < 7; i++) {
        printf(i == 0 ? "%d" : " %d", tempos[i]);
    }
    printf("\n");
    return 0;
}
