// 0100 · Quick sort
// Exercício E597 · ★★☆

#include <stdio.h>
#include <string.h>

static int comparacoes = 0;

void troca(const char **a, const char **b) {
    const char *aux = *a;
    *a = *b;
    *b = aux;
}

int separa(const char *v[], int p, int r) {
    const char *pivo = v[r];
    int j = p;
    for (int k = p; k < r; k++) {
        comparacoes++;
        if (strcmp(v[k], pivo) <= 0) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

void quick_sort(const char *v[], int p, int r) {
    if (p >= r) {
        return;
    }
    int j = separa(v, p, r);
    quick_sort(v, p, j - 1);
    quick_sort(v, j + 1, r);
}

int main(void) {
    const char *compras[] = {"leite", "arroz", "tomate", "café", "pão",
                             "banana", "ovos", "feijão"};
    int n = 8;

    quick_sort(compras, 0, n - 1);
    for (int i = 0; i < n; i++) {
        printf("%s%s", compras[i], i < n - 1 ? ", " : "\n");
    }
    printf("%d comparações\n", comparacoes);
    return 0;
}
