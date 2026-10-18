// 0123 · Quickselect
// Exercício E735 · ★★☆

#include <stdio.h>
#include <stdlib.h>

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

int quickselect(int v[], int n, int k) {
    int p = 0, r = n - 1;
    while (p < r) {
        int j = separa(v, p, r);
        if (j == k) {
            return v[j];
        }
        if (k < j) {
            r = j - 1;
        } else {
            p = j + 1;
        }
    }
    return v[p];
}

// n par: média dos dois do meio. Depois do quickselect em k = n/2 - 1, tudo
// à direita de k é >= v[k]; o outro do meio é o menor desse lado
double mediana(int v[], int n) {
    if (n % 2 == 1) {
        return quickselect(v, n, n / 2);
    }
    int k = n / 2 - 1;
    int a = quickselect(v, n, k);
    int b = v[k + 1];
    for (int i = k + 2; i < n; i++) {
        if (v[i] < b) {
            b = v[i];
        }
    }
    return (a + b) / 2.0;
}

int compara(const void *a, const void *b) {
    int x = *(const int *) a, y = *(const int *) b;
    return (x > y) - (x < y);
}

int main(void) {
    // tempos de entrega do app, em minutos
    int tempos[] = {42, 28, 55, 31, 47, 35, 61, 41, 26, 38};
    int impar[] = {42, 28, 55, 31, 47, 35, 61, 41, 26};

    printf("10 entregas: mediana %.1f min\n", mediana(tempos, 10));
    printf("9 entregas:  mediana %.1f min\n", mediana(impar, 9));

    qsort(tempos, 10, sizeof(int), compara);
    printf("conferindo: %d e %d no meio\n", tempos[4], tempos[5]);
    return 0;
}
