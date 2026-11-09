// Lista · Módulo 14 · Árvores
// Exercício P1417 · ★★☆ · As 4 passagens mais baratas

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void sobe(int h[], int i) {
    while (i > 0 && h[(i - 1) / 2] < h[i]) {
        troca(&h[(i - 1) / 2], &h[i]);
        i = (i - 1) / 2;
    }
}

void desce(int h[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && h[f + 1] > h[f]) {
            f++;
        }
        if (h[i] >= h[f]) {
            break;
        }
        troca(&h[i], &h[f]);
        i = f;
    }
}

int main(void) {
    int precos[] = {780, 455, 920, 610, 390, 1200, 505, 430, 870, 399, 640, 415};
    int n_precos = 12, k = 4;
    int heap[4], n = 0; // heap de MÁXIMO com os k menores vistos até agora

    for (int i = 0; i < n_precos; i++) {
        if (n < k) {
            heap[n] = precos[i];
            sobe(heap, n);
            n++;
        } else if (precos[i] < heap[0]) {
            heap[0] = precos[i]; // o mais caro dos 4 sai
            desce(heap, n, 0);
        }
    }

    // tira do heap: sai do mais caro para o mais barato
    int resposta[4];
    for (int i = k - 1; i >= 0; i--) {
        resposta[i] = heap[0];
        heap[0] = heap[--n];
        desce(heap, n, 0);
    }
    printf("as %d mais baratas:", k);
    for (int i = 0; i < k; i++) {
        printf(" %d", resposta[i]);
    }
    printf("\n");
    return 0;
}
