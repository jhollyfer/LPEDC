// 0132 · Inversões e subvetor de soma máxima
// Exercício E791 · ★★★

#include <stdio.h>

// conta os pares i em [p, q), j em [q, r) com v[i] > 2 * v[j];
// as duas metades já estão ordenadas
int conta_quedas(const int v[], int p, int q, int r) {
    int total = 0;
    int j = q;
    for (int i = p; i < q; i++) {
        while (j < r && v[i] > 2 * v[j]) {
            j++;                // v[j] serve para v[i] e para todos depois dele
        }
        total += j - q;         // v[q..j-1] são menos da metade de v[i]
    }
    return total;
}

void intercala(int v[], int w[], int p, int q, int r) {
    int i = p, j = q, k = 0;
    while (i < q && j < r) {
        w[k++] = v[i] <= v[j] ? v[i++] : v[j++];
    }
    while (i < q) w[k++] = v[i++];
    while (j < r) w[k++] = v[j++];
    for (k = 0; k < r - p; k++) {
        v[p + k] = w[k];
    }
}

int quedas(int v[], int w[], int p, int r) {
    if (r - p < 2) {
        return 0;
    }
    int q = p + (r - p) / 2;
    int total = quedas(v, w, p, q) + quedas(v, w, q, r);
    total += conta_quedas(v, p, q, r);   // primeiro conta, com as metades ordenadas
    intercala(v, w, p, q, r);            // depois junta
    return total;
}

int main(void) {
    int preco[] = {40, 18, 25, 9, 30, 12, 50, 20};
    int n = 8;

    // conferência por força bruta, antes de ordenar
    int bruta = 0;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (preco[i] > 2 * preco[j]) {
                bruta++;
            }
        }
    }

    int w[8];
    printf("Quedas de mais da metade: %d\n", quedas(preco, w, 0, n));
    printf("Força bruta: %d\n", bruta);
    return 0;
}
