// A192 · Cinco algoritmos, a mesma corrida

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define N 1000

static long comparacoes;

// toda comparação de elementos passa por aqui e é contada
static int maior(int a, int b) {
    comparacoes++;
    return a > b;
}

static void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

static void bubble(int v[], int n) {
    int trocou = 1;
    for (int p = 1; p < n && trocou; p++) {
        trocou = 0;
        for (int j = 0; j < n - p; j++) {
            if (maior(v[j], v[j + 1])) {
                troca(&v[j], &v[j + 1]);
                trocou = 1;
            }
        }
    }
}

static void selection(int v[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int m = i;
        for (int j = i + 1; j < n; j++) {
            if (maior(v[m], v[j])) {
                m = j;
            }
        }
        troca(&v[i], &v[m]);
    }
}

static void insertion(int v[], int n) {
    for (int j = 1; j < n; j++) {
        int x = v[j], i = j - 1;
        while (i >= 0 && maior(v[i], x)) {
            v[i + 1] = v[i];
            i--;
        }
        v[i + 1] = x;
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
        w[k++] = maior(v[i], v[j]) ? v[j++] : v[i++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    memcpy(&v[p], w, (size_t) (r - p) * sizeof v[0]);
}

static void merge(int v[], int n) {
    int *w = malloc((size_t) n * sizeof *w);
    if (w == NULL) {
        return;
    }
    merge_rec(v, w, 0, n);
    free(w);
}

static void quick_rec(int v[], int p, int r) {
    if (p >= r) {
        return;
    }
    int j = p;
    for (int k = p; k < r; k++) {
        if (!maior(v[k], v[r])) {      // v[k] <= pivô
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    quick_rec(v, p, j - 1);
    quick_rec(v, j + 1, r);
}

static void quick(int v[], int n) {
    quick_rec(v, 0, n - 1);
}

// gerador de números próprio: dá a mesma sequência em qualquer máquina
static unsigned semente = 2024;
static int sorteia(void) {
    semente = semente * 1103515245u + 12345u;
    return (int) ((semente >> 16) % 10000);
}

int main(void) {
    static int base[3][N], v[N];
    for (int i = 0; i < N; i++) {
        base[0][i] = sorteia();       // aleatório
        base[1][i] = i;               // já ordenado
        base[2][i] = N - i;           // invertido
    }
    const char *nomes[] = {"bubble", "selection", "insertion", "merge", "quick"};
    void (*algoritmos[])(int[], int) = {bubble, selection, insertion, merge, quick};

    printf("n = 1000    aleatório   ordenado  invertido\n"); // alinhado à mão: o "ó" ocupa 2 bytes
    for (int a = 0; a < 5; a++) {
        printf("%-10s", nomes[a]);
        for (int c = 0; c < 3; c++) {
            memcpy(v, base[c], sizeof v);
            comparacoes = 0;
            algoritmos[a](v, N);
            printf(" %10ld", comparacoes);
        }
        printf("\n");
    }
    return 0;
}
// Saída:
// n = 1000    aleatório   ordenado  invertido
// bubble         499122        999     499500
// selection      499500     499500     499500
// insertion      241308        999     499500
// merge            8696       4932       5044
// quick           10972     499500     499500
