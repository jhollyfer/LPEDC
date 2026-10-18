// 0099 · Merge sort
// Exercício E593 · ★★★
//
// Resposta: na cópia de volta, o rascunho w[0..r-p-1] vai para v[k], ou seja,
// para o COMEÇO do vetor, e não para v[p + k], o lugar do pedaço. Só as
// intercalações com p = 0 caem no lugar certo. Já a primeira de todas,
// [1, 2) com [2, 3), escreve 5 e 42 em v[0] e v[1]: o 21 some e o 42 fica
// duplicado. Conserto: v[p + k] = w[k].

#include <stdio.h>
#include <stdlib.h>

void intercala(int v[], int w[], int p, int q, int r) {
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        if (v[i] <= v[j]) {
            w[k++] = v[i++];
        } else {
            w[k++] = v[j++];
        }
    }
    while (i < q) {
        w[k++] = v[i++];
    }
    while (j < r) {
        w[k++] = v[j++];
    }
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
}

void merge_sort(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return;
    }
    int q = p + (r - p) / 2;
    merge_sort(v, w, p, q);
    merge_sort(v, w, q, r);
    intercala(v, w, p, q, r);
}

int main(void) {
    int km[] = {21, 5, 42, 10, 15, 3};
    int n = 6;
    int *w = malloc(n * sizeof *w);
    if (w == NULL) {
        return 1;
    }
    merge_sort(km, w, 0, n);
    for (int i = 0; i < n; i++) {
        printf("%d ", km[i]);
    }
    printf("\n");
    free(w);
    return 0;
}
