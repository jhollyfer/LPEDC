// Lista · Módulo 14 · Árvores
// Exercício P1426 · ★★★ · Juntando k listas com um heap

#include <stdio.h>

typedef struct {
    int valor;
    int lista;
    int indice;
} Item;

void troca(Item *a, Item *b) {
    Item t = *a;
    *a = *b;
    *b = t;
}

void sobe(Item h[], int i) {
    while (i > 0 && h[i].valor < h[(i - 1) / 2].valor) {
        troca(&h[i], &h[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void desce(Item h[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && h[f + 1].valor < h[f].valor) {
            f++;
        }
        if (h[i].valor <= h[f].valor) {
            break;
        }
        troca(&h[i], &h[f]);
        i = f;
    }
}

int main(void) {
    int loja0[] = {12, 40, 77};
    int loja1[] = {5, 18, 19, 60, 95};
    int loja2[] = {33};
    int loja3[] = {7, 21, 50, 88};
    const int *listas[] = {loja0, loja1, loja2, loja3};
    int tam[] = {3, 5, 1, 4};
    int k = 4;

    Item heap[4];
    int n = 0;
    for (int l = 0; l < k; l++) { // a frente de cada lista entra no heap
        heap[n] = (Item){listas[l][0], l, 0};
        sobe(heap, n);
        n++;
    }

    printf("juntas:");
    while (n > 0) {
        Item menor = heap[0];
        printf(" %d", menor.valor);
        if (menor.indice + 1 < tam[menor.lista]) {
            // o próximo da mesma lista toma o lugar da raiz
            heap[0] = (Item){listas[menor.lista][menor.indice + 1], menor.lista, menor.indice + 1};
        } else {
            heap[0] = heap[--n]; // a lista acabou: o heap encolhe
        }
        desce(heap, n, 0);
    }
    printf("\n");
    return 0;
}
