// Lista · Módulo 14 · Árvores
// Exercício P1405 · ★☆☆ · O heap de lances do leilão

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

// coloca x no fim e faz subir enquanto for maior que o pai
void insere(int heap[], int *n, int x) {
    int i = (*n)++;
    heap[i] = x;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        troca(&heap[(i - 1) / 2], &heap[i]);
        i = (i - 1) / 2;
    }
}

int main(void) {
    int lances[] = {120, 340, 200, 510, 90, 450, 380};
    int heap[10], n = 0;

    for (int k = 0; k < 7; k++) {
        insere(heap, &n, lances[k]);
        printf("depois do %d:", lances[k]);
        for (int i = 0; i < n; i++) {
            printf(" %d", heap[i]);
        }
        printf("\n");
    }
    return 0;
}
