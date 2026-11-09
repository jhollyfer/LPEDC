// Lista · Módulo 13 · Busca e ordenação
// Exercício P1314 · ★★☆ · Quick sort com a partição de Hoare

#include <stdio.h>

int v[] = {7, 2, 9, 4, 7, 1, 8, 3};
int n = 8;

void mostra(void) {
    for (int k = 0; k < n; k++) {
        printf(" %d", v[k]);
    }
    printf("\n");
}

// Hoare (Cormen, problema 7-1): pivô = v[p]; devolve j com v[p..j] <= v[j+1..r]
int hoare(int p, int r) {
    int x = v[p];
    int i = p - 1, j = r + 1;
    while (1) {
        do {
            j--;
        } while (v[j] > x);
        do {
            i++;
        } while (v[i] < x);
        if (i < j) {
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
        } else {
            return j;
        }
    }
}

void quick(int p, int r) {
    if (p < r) {
        int pivo = v[p];
        int j = hoare(p, r);
        printf("[%d..%d] pivô %d, j = %d:", p, r, pivo, j);
        mostra();
        quick(p, j);
        quick(j + 1, r);
    }
}

int main(void) {
    quick(0, n - 1);
    printf("final:");
    mostra();
    return 0;
}
