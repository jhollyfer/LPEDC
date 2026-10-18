// ordena.c · implementação das quatro ordenações de ordena.h
#include <stdlib.h>
#include <string.h>
#include "ordena.h"

static long comparacoes = 0;

void ord_zera_contagem(void) {
    comparacoes = 0;
}

long ord_contagem(void) {
    return comparacoes;
}

// toda comparação entre elementos passa por aqui
static int menor(int a, int b) {
    comparacoes++;
    return a < b;
}

static void troca(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

void ord_insertion(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i], j = i - 1;
        while (j >= 0 && menor(x, v[j])) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

static void merge_rec(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return;
    }
    int q = p + (r - p) / 2;
    merge_rec(v, w, p, q);
    merge_rec(v, w, q, r);
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        w[k++] = menor(v[j], v[i]) ? v[j++] : v[i++]; // empate: a esquerda primeiro
    }
    while (i < q) {
        w[k++] = v[i++];
    }
    while (j < r) {
        w[k++] = v[j++];
    }
    memcpy(v + p, w, (r - p) * sizeof *v);
}

void ord_merge(int v[], int n) {
    if (n < 2) {
        return;
    }
    int *w = malloc(n * sizeof *w);
    if (w == NULL) {
        exit(1);
    }
    merge_rec(v, w, 0, n);
    free(w);
}

static void desce(int v[], int n, int i) {
    while (2 * i + 1 < n) {
        int f = 2 * i + 1;
        if (f + 1 < n && menor(v[f], v[f + 1])) {
            f++;
        }
        if (!menor(v[i], v[f])) {
            break;
        }
        troca(&v[i], &v[f]);
        i = f;
    }
}

void ord_heap(int v[], int n) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        desce(v, n, i);
    }
    for (int fim = n - 1; fim > 0; fim--) {
        troca(&v[0], &v[fim]);
        desce(v, fim, 0);
    }
}

// ordena v[p..r] (intervalo fechado), partição de Lomuto
static void quick_rec(int v[], int p, int r) {
    if (p >= r) {
        return;
    }
    troca(&v[p + (r - p) / 2], &v[r]); // o pivô é o do meio, levado para o fim
    int pivo = v[r], i = p;
    for (int j = p; j < r; j++) {
        if (menor(v[j], pivo)) {
            troca(&v[i++], &v[j]);
        }
    }
    troca(&v[i], &v[r]);
    quick_rec(v, p, i - 1);
    quick_rec(v, i + 1, r);
}

void ord_quick(int v[], int n) {
    quick_rec(v, 0, n - 1);
}

int ord_confere(const int v[], int n) {
    for (int i = 1; i < n; i++) {
        if (v[i] < v[i - 1]) {
            return 0;
        }
    }
    return 1;
}
