// 0102 · Heap e fila de prioridade
// Exercício E609 · ★★☆

#include <stdio.h>
#include "heap.h"

// tira o máximo e põe x numa descida só
int troca_topo(Heap *h, int x) {
    int maximo = h->v[0];
    h->v[0] = x;
    int i = 0;
    while (2 * i + 1 < h->n) {
        int f = 2 * i + 1;
        if (f + 1 < h->n && h->v[f + 1] > h->v[f]) {
            f++; // o direito é maior
        }
        if (h->v[i] >= h->v[f]) {
            break;
        }
        int t = h->v[i];
        h->v[i] = h->v[f];
        h->v[f] = t;
        i = f;
    }
    return maximo;
}

int main(void) {
    Heap *h = heap_cria(8);
    int valores[] = {15, 35, 25, 45, 5};
    for (int i = 0; i < 5; i++) {
        heap_insere(h, valores[i]);
    }
    printf("depois das 5 inserções: ");
    heap_mostra(h);
    printf("\n");

    int novos[] = {40, 10};
    for (int i = 0; i < 2; i++) {
        int saiu = troca_topo(h, novos[i]);
        printf("saiu %d, entrou %d: ", saiu, novos[i]);
        heap_mostra(h);
        printf("\n");
    }

    heap_libera(h);
    return 0;
}
