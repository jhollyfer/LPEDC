// Lista · Módulo 13 · Busca e ordenação
// Exercício P1304 · ★☆☆ · Selection sort das senhas da farmácia

#include <stdio.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int senhas[] = {27, 12, 44, 8, 31, 19};
    int n = 6, trocas = 0;

    for (int i = 0; i < n - 1; i++) {
        int menor = i;
        for (int j = i + 1; j < n; j++) {
            if (senhas[j] < senhas[menor]) {
                menor = j;
            }
        }
        if (menor != i) {
            int t = senhas[i];
            senhas[i] = senhas[menor];
            senhas[menor] = t;
            trocas++;
        }
        printf("passada %d:", i + 1);
        mostra(senhas, n);
    }
    printf("trocas: %d\n", trocas);
    return 0;
}
