// Lista · Módulo 13 · Busca e ordenação
// Exercício P1305 · ★☆☆ · Insertion sort das encomendas

#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int pesos[] = {14, 9, 22, 5, 17, 9};
    int n = 6;

    for (int j = 1; j < n; j++) {
        int x = pesos[j];
        int i = j - 1;
        while (i >= 0 && pesos[i] > x) {
            pesos[i + 1] = pesos[i];
            i--;
        }
        pesos[i + 1] = x;
        printf("j = %d:", j);
        mostra(pesos, n);
    }
    return 0;
}
