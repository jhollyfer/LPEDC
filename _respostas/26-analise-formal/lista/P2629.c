// Lista · Módulo 26 · Notação assintótica, somatórios e espaço
// Exercício P2629 · ★★★ · Distância de edição em duas linhas

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int menor3(int a, int b, int c) {
    int m = a < b ? a : b;
    return m < c ? m : c;
}

int edicao_tabela(const char *a, const char *b, size_t *bytes) {
    int m = (int)strlen(a), k = (int)strlen(b);
    int *d = malloc((size_t)(m + 1) * (k + 1) * sizeof(int));
    if (d == NULL) {
        return -1;
    }
    *bytes = (size_t)(m + 1) * (k + 1) * sizeof(int);
    for (int i = 0; i <= m; i++) {
        for (int j = 0; j <= k; j++) {
            int *c = &d[i * (k + 1) + j];
            if (i == 0) {
                *c = j;
            } else if (j == 0) {
                *c = i;
            } else {
                *c = menor3(d[(i - 1) * (k + 1) + j] + 1, d[i * (k + 1) + j - 1] + 1,
                            d[(i - 1) * (k + 1) + j - 1] + (a[i - 1] != b[j - 1]));
            }
        }
    }
    int r = d[m * (k + 1) + k];
    free(d);
    return r;
}

int edicao_linhas(const char *a, const char *b, size_t *bytes) {
    int m = (int)strlen(a), k = (int)strlen(b);
    int *ant = malloc((k + 1) * sizeof(int));
    int *atual = malloc((k + 1) * sizeof(int));
    if (ant == NULL || atual == NULL) {
        free(ant);
        free(atual);
        return -1;
    }
    *bytes = 2 * (k + 1) * sizeof(int);
    for (int j = 0; j <= k; j++) {
        ant[j] = j;
    }
    for (int i = 1; i <= m; i++) {
        atual[0] = i;
        for (int j = 1; j <= k; j++) {
            atual[j] = menor3(ant[j] + 1, atual[j - 1] + 1, ant[j - 1] + (a[i - 1] != b[j - 1]));
        }
        int *t = ant;
        ant = atual;
        atual = t;
    }
    int r = ant[k];
    free(ant);
    free(atual);
    return r;
}

int main(void) {
    size_t b1, b2;
    int d1 = edicao_tabela("paralelepipedo", "paralelogramo", &b1);
    int d2 = edicao_linhas("paralelepipedo", "paralelogramo", &b2);
    printf("curtas: tabela %d (%zu bytes), linhas %d (%zu bytes)\n", d1, b1, d2, b2);

    static char a[2001], b[2001];
    for (int i = 0; i < 2000; i++) {
        a[i] = (char)('a' + i % 7);
        b[i] = (char)('a' + i % 5);
    }
    d1 = edicao_tabela(a, b, &b1);
    d2 = edicao_linhas(a, b, &b2);
    printf("longas: tabela %d (%zu bytes), linhas %d (%zu bytes)\n", d1, b1, d2, b2);
    return 0;
}
