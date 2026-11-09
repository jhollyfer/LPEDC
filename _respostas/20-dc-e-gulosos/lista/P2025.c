// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2025 · ★★★ · A mediana das medianas

#include <stdio.h>
#include <stdlib.h>

#define N 23

void ordena(int v[], int n) {
    for (int i = 1; i < n; i++) {
        int x = v[i], j = i - 1;
        while (j >= 0 && v[j] > x) {
            v[j + 1] = v[j];
            j--;
        }
        v[j + 1] = x;
    }
}

int seleciona(const int v[], int n, int k) {
    if (n <= 5) {
        int t[5];
        for (int i = 0; i < n; i++) {
            t[i] = v[i];
        }
        ordena(t, n);
        return t[k];
    }
    int ng = (n + 4) / 5;
    int *med = malloc((size_t)ng * sizeof *med);
    if (med == NULL) {
        exit(1);
    }
    for (int g = 0; g < ng; g++) {
        int t[5], m = 0;
        for (int i = 5 * g; i < n && i < 5 * g + 5; i++) {
            t[m++] = v[i];
        }
        ordena(t, m);
        med[g] = t[m / 2];
    }
    int piv = seleciona(med, ng, ng / 2);
    free(med);
    int *men = malloc((size_t)n * sizeof *men);
    int *mai = malloc((size_t)n * sizeof *mai);
    if (men == NULL || mai == NULL) {
        exit(1);
    }
    int nmen = 0, nmai = 0, nig = 0;
    for (int i = 0; i < n; i++) {
        if (v[i] < piv) {
            men[nmen++] = v[i];
        } else if (v[i] > piv) {
            mai[nmai++] = v[i];
        } else {
            nig++;
        }
    }
    int r;
    if (k < nmen) {
        r = seleciona(men, nmen, k);
    } else if (k < nmen + nig) {
        r = piv;
    } else {
        r = seleciona(mai, nmai, k - nmen - nig);
    }
    free(men);
    free(mai);
    return r;
}

int crescente(const void *a, const void *b) {
    int x = *(const int *)a, y = *(const int *)b;
    return (x > y) - (x < y);
}

int main(void) {
    int v[N] = {67, 82, 45, 91, 58, 73, 66, 49, 88, 70, 54, 95,
                61, 77, 41, 85, 63, 98, 52, 69, 80, 47, 75};
    int menor = seleciona(v, N, 0), mediana = seleciona(v, N, N / 2), maior = seleciona(v, N, N - 1);
    qsort(v, N, sizeof v[0], crescente);
    printf("Menor: %d (qsort: %d)\n", menor, v[0]);
    printf("Mediana: %d (qsort: %d)\n", mediana, v[N / 2]);
    printf("Maior: %d (qsort: %d)\n", maior, v[N - 1]);
    return 0;
}
