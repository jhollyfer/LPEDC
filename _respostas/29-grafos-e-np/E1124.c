// 0188 · Aproximação
// Exercício E1124 · ★☆☆

#include <stdio.h>

#define N 8
#define CAPACIDADE 16 // GB por pendrive

int main(void) {
    int arquivo[N] = {9, 7, 5, 8, 3, 6, 4, 2};
    int livre[N], conteudo[N][N], qtd[N], usados = 0;

    for (int i = 0; i < N; i++) {
        int melhor = -1; // o pendrive que fica MAIS cheio depois de receber o arquivo
        for (int p = 0; p < usados; p++)
            if (livre[p] >= arquivo[i] && (melhor == -1 || livre[p] < livre[melhor])) melhor = p;
        if (melhor == -1) melhor = usados, livre[usados] = CAPACIDADE, qtd[usados] = 0, usados++;
        livre[melhor] -= arquivo[i];
        conteudo[melhor][qtd[melhor]++] = arquivo[i];
    }
    printf("Best fit: %d pendrives\n", usados);
    for (int p = 0; p < usados; p++) {
        printf("  pendrive %d:", p + 1);
        for (int k = 0; k < qtd[p]; k++) printf(" %d", conteudo[p][k]);
        printf("  (sobram %d GB)\n", livre[p]);
    }
    return 0;
}
