// Lista · Módulo 13 · Busca e ordenação
// Exercício P1303 · ★☆☆ · O bubble passada a passada

#include <stdio.h>
#include <stdbool.h>

void mostra(const int v[], int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d", v[i]);
    }
    printf("\n");
}

int main(void) {
    int gols[] = {3, 0, 5, 1, 4, 2};
    int n = 6;

    for (int passada = 1; passada < n; passada++) {
        bool trocou = false;
        for (int j = 0; j < n - passada; j++) {
            if (gols[j] > gols[j + 1]) {
                int t = gols[j];
                gols[j] = gols[j + 1];
                gols[j + 1] = t;
                trocou = true;
            }
        }
        printf("passada %d:", passada);
        mostra(gols, n);
        if (!trocou) {
            printf("nenhuma troca: parou\n");
            break;
        }
    }
    return 0;
}
