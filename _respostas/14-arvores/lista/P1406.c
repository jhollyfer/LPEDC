// Lista · Módulo 14 · Árvores
// Exercício P1406 · ★☆☆ · Chamando os pacientes mais urgentes

#include <stdio.h>

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce(int heap[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && heap[f + 1] > heap[f]) {
            f++;
        }
        if (heap[i] >= heap[f]) {
            break;
        }
        troca(&heap[i], &heap[f]);
        i = f;
    }
}

int extrai_max(int heap[], int *n) {
    int max = heap[0];
    heap[0] = heap[--(*n)];
    desce(heap, *n, 0);
    return max;
}

int main(void) {
    int urgencia[] = {95, 80, 70, 40, 75, 30, 65, 10};
    int n = 8;

    for (int k = 0; k < 3; k++) {
        int u = extrai_max(urgencia, &n);
        printf("chamou %d, sobrou:", u);
        for (int i = 0; i < n; i++) {
            printf(" %d", urgencia[i]);
        }
        printf("\n");
    }
    return 0;
}
