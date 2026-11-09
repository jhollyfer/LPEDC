// Lista · Módulo 20 · Divisão e conquista e algoritmos gulosos
// Exercício P2029 · ★★★ · Juntando as notas de quatro turmas

#include <stdio.h>
#include <string.h>

#define K 4
#define TOTAL 17

int comps = 0;

int intercala(const int a[], int na, const int b[], int nb, int s[]) {
    int i = 0, j = 0, k = 0;
    while (i < na && j < nb) {
        comps++;
        if (a[i] <= b[j]) {
            s[k++] = a[i++];
        } else {
            s[k++] = b[j++];
        }
    }
    while (i < na) {
        s[k++] = a[i++];
    }
    while (j < nb) {
        s[k++] = b[j++];
    }
    return k;
}

const int t0[] = {52, 61, 78, 90, 95}, t1[] = {48, 55, 70};
const int t2[] = {35, 66, 74, 81, 88, 93, 99}, t3[] = {40, 59};
const int *lista[K] = {t0, t1, t2, t3};
const int tam[K] = {5, 3, 7, 2};

int junta(int ini, int fim, int s[]) {
    if (ini == fim) {
        memcpy(s, lista[ini], (size_t)tam[ini] * sizeof s[0]);
        return tam[ini];
    }
    int meio = (ini + fim) / 2;
    int e[TOTAL], d[TOTAL];
    int ne = junta(ini, meio, e);
    int nd = junta(meio + 1, fim, d);
    return intercala(e, ne, d, nd, s);
}

int main(void) {
    int acum[TOTAL], tmp[TOTAL];
    comps = 0;
    int n = tam[0];
    memcpy(acum, lista[0], (size_t)n * sizeof acum[0]);
    for (int t = 1; t < K; t++) {
        n = intercala(acum, n, lista[t], tam[t], tmp);
        memcpy(acum, tmp, (size_t)n * sizeof acum[0]);
    }
    int seq = comps;
    comps = 0;
    int dc[TOTAL];
    int m = junta(0, K - 1, dc);
    printf("Lista:");
    for (int i = 0; i < m; i++) {
        printf(" %d", dc[i]);
    }
    printf("\n");
    printf("Uma a uma: %d comparações\n", seq);
    printf("Divisão e conquista: %d comparações\n", comps);
    int iguais = n == m;
    for (int i = 0; i < m && iguais; i++) {
        iguais = acum[i] == dc[i];
    }
    printf("Listas iguais: %s\n", iguais ? "sim" : "não");
    return 0;
}
