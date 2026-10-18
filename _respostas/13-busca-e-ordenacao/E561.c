// 0094 · Merge sort
// Exercício E561 · ★★☆

#include <stdio.h>

// união sem repetidos de a e b (ordenados, sem repetidos dentro de cada um)
int uniao(const int a[], int na, const int b[], int nb, int c[], int *nos_dois) {
    int i = 0, j = 0, k = 0;
    *nos_dois = 0;
    while (i < na && j < nb) {
        if (a[i] < b[j]) {
            c[k++] = a[i++];
        } else if (a[i] > b[j]) {
            c[k++] = b[j++];
        } else {                 // igual: entra uma vez e as duas andam
            c[k++] = a[i];
            i++;
            j++;
            (*nos_dois)++;
        }
    }
    while (i < na) {
        c[k++] = a[i++];
    }
    while (j < nb) {
        c[k++] = b[j++];
    }
    return k;
}

int main(void) {
    int manha[] = {1021, 1034, 1050, 1077, 1090};
    int tarde[] = {1010, 1034, 1066, 1077, 1095, 1102};
    int todos[11];
    int nos_dois;

    int n = uniao(manha, 5, tarde, 6, todos, &nos_dois);
    printf("%d alunos diferentes:", n);
    for (int k = 0; k < n; k++) {
        printf(" %d", todos[k]);
    }
    printf("\nforam nos dois turnos: %d\n", nos_dois);
    return 0;
}
