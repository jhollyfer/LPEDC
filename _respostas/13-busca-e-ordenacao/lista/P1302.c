// Lista · Módulo 13 · Busca e ordenação
// Exercício P1302 · ★☆☆ · Quantas voltas a busca binária dá

#include <stdio.h>

int busca_binaria(const int v[], int n, int x, int *voltas) {
    int ini = 0, fim = n - 1;
    *voltas = 0;
    while (ini <= fim) {
        int meio = ini + (fim - ini) / 2;
        (*voltas)++;
        if (v[meio] == x) {
            return meio;
        }
        if (v[meio] < x) {
            ini = meio + 1;
        } else {
            fim = meio - 1;
        }
    }
    return -1;
}

int main(void) {
    int precos[] = {3, 7, 12, 15, 19, 24, 28, 33, 41, 47, 52, 60, 68, 75, 89};
    int n = 15;
    int alvos[] = {33, 28, 3, 89, 50};
    int voltas;

    for (int k = 0; k < 5; k++) {
        int pos = busca_binaria(precos, n, alvos[k], &voltas);
        printf("R$ %d: posição %d (voltas: %d)\n", alvos[k], pos, voltas);
    }
    return 0;
}
