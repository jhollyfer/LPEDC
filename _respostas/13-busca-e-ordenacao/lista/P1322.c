// Lista · Módulo 13 · Busca e ordenação
// Exercício P1322 · ★★★ · Três filiais, uma fila de pedidos

#include <stdio.h>

int comparacoes;

// devolve 1 se a fila ainda tem gente e a frente dela é menor que a da outra
static int menor(const int v[], int i, int n, const int w[], int j, int m) {
    if (i >= n) {
        return 0;
    }
    if (j >= m) {
        return 1;
    }
    comparacoes++;
    return v[i] <= w[j];
}

// intercala três vetores ordenados de uma vez
int intercala3(const int a[], int na, const int b[], int nb, const int c[], int nc, int s[]) {
    int i = 0, j = 0, k = 0, t = 0;
    while (i < na || j < nb || k < nc) {
        if (menor(a, i, na, b, j, nb) && menor(a, i, na, c, k, nc)) {
            s[t++] = a[i++];
        } else if (menor(b, j, nb, c, k, nc)) {
            s[t++] = b[j++];
        } else {
            s[t++] = c[k++];
        }
    }
    return t;
}

int intercala2(const int a[], int na, const int b[], int nb, int s[]) {
    int i = 0, j = 0, t = 0;
    while (i < na && j < nb) {
        comparacoes++;
        s[t++] = (a[i] <= b[j]) ? a[i++] : b[j++];
    }
    while (i < na) {
        s[t++] = a[i++];
    }
    while (j < nb) {
        s[t++] = b[j++];
    }
    return t;
}

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int centro[] = {3, 10, 21, 30};
    int norte[] = {1, 12, 18};
    int sul[] = {5, 7, 25, 40};
    int s[11], tmp[7];

    comparacoes = 0;
    int n = intercala3(centro, 4, norte, 3, sul, 4, s);
    printf("de uma vez:");
    mostra(s, n);
    printf("comparações: %d\n", comparacoes);

    comparacoes = 0;
    int m = intercala2(centro, 4, norte, 3, tmp);
    n = intercala2(tmp, m, sul, 4, s);
    printf("duas a duas:");
    mostra(s, n);
    printf("comparações: %d\n", comparacoes);
    return 0;
}
