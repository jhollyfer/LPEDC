// A216 · Heapsort não tem dia ruim

#include <stdio.h>
#include <stdlib.h>

long comparacoes = 0; // contador global, só para o experimento

void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n) {
            comparacoes++;
            if (v[f + 1] > v[f]) {
                f++;
            }
        }
        comparacoes++;
        if (v[i] >= v[f]) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void heapsort(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
    }
}

void insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i];
        int j = i - 1;
        while (j >= 0) {
            comparacoes++;
            if (v[j] <= x) {
                break;
            }
            v[j + 1] = v[j]; // empurra para a direita
            j--;
        }
        v[j + 1] = x;
    }
}

int main(void) {
    int n = 1000;
    int *a = malloc(n * sizeof(int));
    int *b = malloc(n * sizeof(int));
    if (a == NULL || b == NULL) {
        return 1;
    }
    for (int i = 0; i < n; i++) {
        a[i] = b[i] = n - i; // decrescente: o pior caso do insertion sort
    }

    comparacoes = 0;
    insertion(a, n);
    printf("Insertion sort: %ld comparações\n", comparacoes);

    comparacoes = 0;
    heapsort(b, n);
    printf("Heapsort:       %ld comparações\n", comparacoes);

    printf("Ordenados? %s\n", a[0] == 1 && a[n - 1] == n && b[0] == 1 && b[n - 1] == n ? "sim" : "não");
    free(a);
    free(b);
    return 0;
}
// Saída:
// Insertion sort: 499500 comparações
// Heapsort:       15965 comparações
// Ordenados? sim
