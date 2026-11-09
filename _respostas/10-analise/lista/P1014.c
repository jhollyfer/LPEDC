// Lista · Módulo 10 · Pensar como cientista da computação
// Exercício P1014 · ★★☆ · Separar débitos e créditos no lugar

#include <assert.h>
#include <stdbool.h>
#include <stdio.h>

int trocas = 0;

// v[0..i-1] < 0 e v[i..j-1] >= 0
bool invariante(const int v[], int i, int j) {
    for (int k = 0; k < i; k++) {
        if (v[k] >= 0) {
            return false;
        }
    }
    for (int k = i; k < j; k++) {
        if (v[k] < 0) {
            return false;
        }
    }
    return true;
}

int separa(int v[], int n) {
    int i = 0;
    for (int j = 0; j < n; j++) {
        assert(invariante(v, i, j));
        if (v[j] < 0) {
            int t = v[i];
            v[i] = v[j];
            v[j] = t;
            i++;
            trocas++;
        }
    }
    assert(invariante(v, i, n)); // término
    return i;
}

int main(void) {
    int extrato[8] = {120, -30, 45, -80, -10, 60, 0, -5};
    int d = separa(extrato, 8);
    printf("Débitos:");
    for (int k = 0; k < d; k++) {
        printf(" %d", extrato[k]);
    }
    printf("\nCréditos:");
    for (int k = d; k < 8; k++) {
        printf(" %d", extrato[k]);
    }
    printf("\nTrocas: %d\n", trocas);
    return 0;
}
