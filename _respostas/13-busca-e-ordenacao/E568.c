// 0095 · Quick sort
// Exercício E568 · ★★☆

#include <stdio.h>

void troca(int *a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int separa(int v[], int p, int r) {
    int pivo = v[r], j = p;
    for (int k = p; k < r; k++) {
        if (v[k] <= pivo) {
            troca(&v[j], &v[k]);
            j++;
        }
    }
    troca(&v[j], &v[r]);
    return j;
}

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(i == 0 ? "%d" : " %d", v[i]);
    }
}

void quick_sort(int v[], int n, int p, int r) {
    if (p >= r) {
        return;
    }
    int j = separa(v, p, r);
    printf("separa [%d..%d]: pivô na posição %d -> ", p, r, j);
    mostra(v, n);
    printf("\n");
    quick_sort(v, n, p, j - 1);
    quick_sort(v, n, j + 1, r);
}

int main(void) {
    int andares[] = {4, 9, 2, 7, 5, 1};
    quick_sort(andares, 6, 0, 5);
    printf("Final: ");
    mostra(andares, 6);
    printf("\n");
    return 0;
}
