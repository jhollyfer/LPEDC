// 0123 · Quickselect
// Exercício E734 · ★☆☆

#include <stdio.h>
#include <stdbool.h>

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

// k contado a partir de 1, como as pessoas falam: 1 = o menor
bool k_esimo_menor(int v[], int n, int k, int *resposta) {
    if (k < 1 || k > n) {
        return false;
    }
    *resposta = quickselect(v, n, k - 1);
    return true;
}

int main(void) {
    // distâncias (em km) das 7 farmácias mais perto de casa
    int distancias[] = {12, 3, 25, 7, 18, 1, 9};
    int pedidos[] = {1, 3, 7, 0, 8};
    for (int i = 0; i < 5; i++) {
        int r;
        if (k_esimo_menor(distancias, 7, pedidos[i], &r)) {
            printf("%dª mais perto: %d km\n", pedidos[i], r);
        } else {
            printf("%dª mais perto: não existe\n", pedidos[i]);
        }
    }
    return 0;
}
